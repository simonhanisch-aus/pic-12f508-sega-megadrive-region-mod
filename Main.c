// CONFIG
#pragma config OSC = IntRC      // Oscillator Selection bits (external RC oscillator)
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection off)
#pragma config MCLRE = ON       // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is MCLR)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include "DFO-Registers.h"
#include <xc.h>

//OSCCAL 0C22
static volatile uint8_t GPIO_SHADOW;
static volatile uint8_t STATUS_REG = 0x0F; //
static volatile uint8_t SDA_SHADOW = 0x01; //
#define STATUS_REG_REGION 0
#define STATUS_REG_STATUS 1
#define STATUS_REG_ERROR 2
#define STATUS_REG_RETRY 3
#define STATUS_REG_WAIT 4 //4-7 wait timer 
#define _XTAL_FREQ 4000000    // Required for __delay_ms()
#define SCL_PIN  0
#define STATUS_PIN  5
#define REGION_IN_PIN  2
#define SDA_PIN  1
#define MCLRE_PIN  3
#define STATUS_CLOCK_PIN 4 // GP4
#define TRIS_DEFAULT 0x0F
#define GPIO_DEFAULT 0x30
// GP5 unused

#define SI5351_ADDR 0x60 << 1   // 0x60 << 1 (write mode)
#define SI5351_ADDR_READ SI5351_ADDR | 1   // (0x60 << 1 | 1)  (read mode)
#define SI5351_REG_OUTPUT_EN 0x03

#define WAIT() (__delay_us(10))

// inverted logic, 1 = write

void i2c_set(uint8_t mask) {
    TRIS = TRIS_DEFAULT & ~((mask & (1 << SCL_PIN)) | ((SDA_SHADOW & 1) << SDA_PIN));
    WAIT();
    do {
        SDA_SHADOW = (mask >> SDA_PIN) & 1;
        TRIS = TRIS_DEFAULT & ~(mask);
        WAIT();
    } while (0);

}

void gpio_set(uint8_t mask) {

    GPIO_SHADOW = GPIO_DEFAULT & ~(mask);
    GPIO = GPIO_SHADOW;
}

void status_reg_set(uint8_t mask) {

    STATUS_REG |= mask;
}

void status_reg_clr(uint8_t mask) {

    STATUS_REG &= ~mask;
}

void i2c_start(void) {
    // SDA high, SCL high, then SDA low (while SCL high)
    i2c_set(0x00);
    i2c_set(0x01 << SDA_PIN);
}

void i2c_stop(void) {
    // SDA low, SCL high, then SDA high (while SCL high)

    i2c_set(0x01 << SCL_PIN | 0x01 << SDA_PIN);
    i2c_set(0x00);
}

void ACK() {

    //ACK
    i2c_set(0x01 << SCL_PIN);
    i2c_set(0x00);

    status_reg_clr((uint8_t) (((GPIO & (uint8_t) (1 << SDA_PIN)) != 0) << STATUS_REG_ERROR));
}

void NACK() {
    //ACK
    i2c_set(0x01 << SCL_PIN);
    i2c_set(0x00);
}

uint8_t i2c_write(unsigned char byte) {

    uint8_t result = 0x0;
    // For each of 8 bits: set SDA, pulse SCL high then low
    // Then read ACK

    for (uint8_t i = 8; i > 0; i--) {
        byte = (uint8_t) (byte << 1u) | (uint8_t) (byte >> 7u);
        // Invert the bit to pull down when 0
        i2c_set((1 << SCL_PIN) | ((byte & 1) == 0) << SDA_PIN);

        i2c_set(((byte & 1) == 0) << SDA_PIN);
        //wait for clock stretching    
        while (((GPIO & (1 << SCL_PIN)) == 0) & (STATUS_REG < 0xE0)) {
            __delay_ms(1);
            STATUS_REG = (STATUS_REG + 0x10);
        }
        status_reg_clr(0xF0);
        result = (uint8_t) (result << 1) | (GPIO & (1 << SDA_PIN));
    }

    return result;
}

void main(void) {

    // TRIS sets pin direction: 1 = input, 0 = output
    //GP0 SCL
    //GP2 SDA
    //GP3 PAL/NTSC IN (L/H)
    //GP4 ERROR (active low)
    TRIS = TRIS_DEFAULT;
    SDA_SHADOW = 0x0;
    gpio_set(0x0);

    // OPTION register: bit 6 (GPPU) controls weak pull-ups
    // bit 5 (T0CS) = 0 for internal timer, 
    // bit 3 (PSA) = 1 to assign prescaler to WDT (so TMR0 ticks fast)
    OPTION = 0x4f;
    OSCCAL = 0x2A;

    //Sync shadow GPIO with input pin states
    status_reg_clr((GPIO & (1 << REGION_IN_PIN)) == 0 << STATUS_REG_REGION);

    // Write registers to Si5351 to configure clocks
    for (uint8_t i = 0; i < SI5351A_REVB_REG_CONFIG_NUM_REGS; i++) {

        i2c_start();
        i2c_write(SI5351_ADDR);
        ACK();
        i2c_write(si5351a_revb_registers[i].address);
        ACK();
        if (i == SI5351A_REVB_REG_CONFIG_NUM_REGS - 1) {
            //Give time for PLLs to stabilise before enabling clock outputs
            __delay_ms(50);
            i2c_write(clock_enable_values[!!(STATUS_REG & (1 << STATUS_REG_REGION))]);
        } else {
            i2c_write(si5351a_revb_registers[i].value);
        }
        ACK();
        i2c_stop();
        if ((STATUS_REG & (1 << STATUS_REG_ERROR)) == 0) {
            if ((STATUS_REG & (1 << STATUS_REG_RETRY)) == 0) {
                break;
            }
            status_reg_clr(1 << STATUS_REG_RETRY);
            status_reg_set((1 << STATUS_REG_ERROR));
            i--;
        } else {
            status_reg_set(1 << STATUS_REG_RETRY);
        }
    }


    //Make sure that GPIO is reset and being driven low as intended
    i2c_start();
    i2c_write(SI5351_ADDR);
    ACK();
    i2c_write(0x00);
    ACK();
    i2c_stop();

    i2c_start();
    i2c_write(SI5351_ADDR_READ);
    ACK();
    uint8_t status_read = i2c_write(0x0);
    status_reg_set(1 << STATUS_REG_STATUS);
    status_reg_clr((uint8_t) (((status_read | 0x13) != 0x13) << STATUS_REG_STATUS)); // Bits 7 6 5 3 should trigger an alert
    NACK();
    i2c_stop();

    uint8_t statusByte = STATUS_REG;
    while (1) {
        statusByte = ((uint8_t) (statusByte << 1u) | (uint8_t) (statusByte >> 7u));
        gpio_set((uint8_t) (((statusByte & 1) == 1) << STATUS_PIN) | 1 << STATUS_CLOCK_PIN);
        __delay_ms(500);
        gpio_set(0x0);
        __delay_ms(200);
        if (statusByte == STATUS_REG) {
            __delay_ms(1000);
        }
        // Do nothing forever, or put background tasks here
    }
}

