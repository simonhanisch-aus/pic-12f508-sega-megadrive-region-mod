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
static volatile uint8_t STATUS_REG = 0x0F;
static volatile uint8_t SDA_SHADOW = 0x01;
static volatile uint8_t CLOCK_ENABLE_VAL = 0xFF;

#define STATUS_REG_REGION 0
#define STATUS_REG_PAL60 1
#define STATUS_REG_ERROR 2
#define STATUS_REG_RETRY 3
#define STATUS_REG_WAIT 4 //4-7 wait timer 
#define _XTAL_FREQ 4000000    // Required for __delay_ms()

//PIN MAPPING
#define REGION_IN_PIN 0 // NTSC/PAL - wake up on pin change
#define PAL_SUBCR_EN_PIN 1  // ENABLE 4.43(...)MHz output on CLK1/OFF  - wake up on pin change
#define STATUS_ERROR_PIN 2 // OFF/ON
#define MCLRE_PIN 3 // tie this to MRES on console
#define SCL_PIN 4 //Si5351 SCL pin is 4 on the MSOP so this is best for trace routing
#define SDA_PIN 5 //We dont need to listen to any i2c communication attempts from the Si so dont need to waste a wake up pin on it

#define TRIS_DEFAULT 0xFB
#define GPIO_DEFAULT 0xFF
//OPTION GPWU | GPPU | T0CS | T0SE | PSA | PS2 | PS1 | PS0
#define OPTION_DEFAULT 0x0F

#define SI5351_REG_OUTPUT_EN 0x03

#define WAIT() (__delay_us(10))

#define ACK()                      \
    do {                            \
        i2c_set(0x01 << SCL_PIN);   \
        i2c_set(0x00);              \
    } while(0)

#define status_reg_set(mask)          \
    do {                              \
        STATUS_REG |= (uint8_t) mask; \
    } while(0)

#define status_reg_clr(mask)          \
    do {                              \
    STATUS_REG &= ~((uint8_t) mask);  \
    } while(0)

void gpio_set(uint8_t mask)       {
    GPIO_SHADOW = GPIO_DEFAULT & ~(mask); 
    GPIO = GPIO_SHADOW;       
}

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

// SDA low, SCL high, then SDA high (while SCL high)
void i2c_stop(void) {
    i2c_set(0x01 << SCL_PIN | 0x01 << SDA_PIN);
    i2c_set(0x00);
}

// SDA high, SCL high, then SDA low (while SCL high)
void i2c_start(void) {
    i2c_set(0x00);
    i2c_set(0x01 << SDA_PIN);
}
uint8_t i2c_write(unsigned char byte) {

    uint8_t result = 0x0;
    // For each of 8 bits: set SDA, pulse SCL high then low
    // Then read ACK

    for (uint8_t i = 8; i > 0; i--) {
        byte = (uint8_t) (byte << 1u) | (uint8_t) (byte >> 7u);
        // Invert the bit to pull down when 0
        i2c_set((uint8_t)((1 << SCL_PIN) | ((byte & 1) == 0) << SDA_PIN));

        i2c_set((uint8_t)(((byte & 1) == 0) << SDA_PIN));
        //wait for clock stretching    
        while (((GPIO & (1 << SCL_PIN)) == 0) & (STATUS_REG < 0xE0)) {
            __delay_ms(1);
            STATUS_REG = (STATUS_REG + 0x10);
        }
        status_reg_clr(0xF0);
        result = (uint8_t) (result << 1) | (GPIO & (1 << SDA_PIN));
    }
    ACK();

    return result;
}
void main(void) {

    // Set default values for shadow registers etc.
    TRIS = TRIS_DEFAULT;
    SDA_SHADOW = 0x0;
    gpio_set(0x0);
    OPTION = OPTION_DEFAULT;

    // Write registers to Si5351 to configure clocks
    for (uint8_t i = SI5351A_REVB_REG_CONFIG_NUM_REGS-1; i > 0; i--) {

        i2c_start();
        i2c_write(SI5351_ADDR);
        i2c_write(si5351a_revb_registers[i]);
        i2c_write(si5351a_revb_registers_values[i]);
        
        // If the Si5351 NACKs...
        if ((GPIO & (uint8_t)(1 << SDA_PIN)) != 0) {
            if ((STATUS_REG & (1 << STATUS_REG_RETRY)) == 0) {
                break;
            }
            status_reg_clr(1 << STATUS_REG_RETRY);
            i++;
        } else {
            status_reg_set(1 << STATUS_REG_RETRY);
        }
        i2c_stop();
    }

    
    // Start loop - set clock output enable and check status registers to make sure there are no
    // issues. Sleep if all looking good. Changing either the NETSC/PAL or PAL60 pin will reset the microcontroller
    // as will resetting the console.
    uint8_t counter = 0x0A;
    uint8_t has_error = 0x00; 
    CLOCK_ENABLE_VAL = 0xFF;
    while (1) {
    
        //Sync shadow GPIO with input pin states
        status_reg_set((1 << REGION_IN_PIN) | (1 << STATUS_REG_REGION));
        status_reg_clr(GPIO & (((1 << REGION_IN_PIN) == 0) << STATUS_REG_REGION) | (((1 << PAL_SUBCR_EN_PIN)) << STATUS_REG_PAL60));
        CLOCK_ENABLE_VAL = clock_enable_values[(STATUS_REG & (1 << STATUS_REG_REGION)) + (STATUS_REG & (1 << STATUS_REG_REGION))];
        // Read status register and output a LED if clock/pll/xtal error is found
        // Read clock enable status        
        
            __delay_ms(1000);
        for (uint8_t i = SI5351A_REVB_REG_READ_NUM_REGS-1; i > 0; i--) {
            i2c_start();
            i2c_write(si5351a_revb_read_addresses[i]);
            uint8_t read_value = i2c_write(si5351a_revb_read_registers[i]);
            if (i == SI5351A_REVB_REG_READ_NUM_REGS-1) {        
                i2c_write(CLOCK_ENABLE_VAL);
            } 
            
            // set error LED
            has_error = 0x00;                 
            has_error |= (i | (read_value & 0x78)) == 0x00; // Bits 7 6 5 4 3 should trigger an alert (set low)                
            has_error |= ((i & ~(2)) | (read_value ^ CLOCK_ENABLE_VAL)) == 0x00; // should be the same value        
            gpio_set((uint8_t)(has_error << STATUS_ERROR_PIN));
            
            i2c_stop();
        }     
        
        counter--;
        
        // Go into sleep mode if counter expires or status is reporting no issues
        if ((has_error == 0 ) | (counter == 0)) {
            SLEEP();
        }
    }
}

