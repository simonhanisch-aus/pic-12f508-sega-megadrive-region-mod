// CONFIG
#pragma config OSC = IntRC      // Oscillator Selection bits (external RC oscillator)
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection off)
#pragma config MCLRE = ON       // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is MCLR)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include "registers/si5351_registers.h"
#include "headers/constants.h"
#include "headers/pic_functions.h"
#include "headers/i2c.h"
#include "headers/status_management.h"

static volatile uint8_t clock_enable_val = 0xFF;
static volatile uint8_t counter = 0x0A;
static volatile uint8_t has_error = 0x00;
volatile uint8_t status_reg = 0x0F;

void gpio_set(unsigned char mask) {
    gpio_shadow = GPIO_DEFAULT & ~(mask);
    GPIO = gpio_shadow;
}

void main(void) {

    // Set default values for shadow registers etc.
    TRIS = TRIS_DEFAULT;
    sda_shadow = 0x0;
    gpio_set(0x0);
    OPTION = OPTION_DEFAULT;

    // Write registers to Si5351 to configure clocks
    for (uint8_t i = 0; i < SI5351A_REVB_REG_CONFIG_NUM_REGS; i++) {

        i2c_start();
        i2c_write(SI5351_ADDR);
        i2c_write(si5351a_revb_registers[i]);
        i2c_write(si5351a_revb_registers_values[i]);

        // If the Si5351 NACKs...
        if ((GPIO & (uint8_t) (1 << SDA_PIN)) != 0) {
            if ((status_reg & (1 << STATUS_REG_RETRY)) == 0) {
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
    clock_enable_val = 0xFF;
    while (1) {

        clock_enable_val = clock_enable_values[GPIO & (1 << REGION_IN_PIN | 1 << PAL_SUBCR_EN_PIN)];
        // Read status register and output a LED if clock/pll/xtal error is found
        // Read clock enable status

        __delay_ms(100);
        has_error = 0x00;
        for (uint8_t i = SI5351A_REVB_REG_READ_NUM_REGS; i > 0; i--) {
            i2c_start();
            i2c_write(si5351a_revb_read_addresses[i - 1]);
            uint8_t read_value = i2c_write(si5351a_revb_read_registers[i - 1]);
            if (i == SI5351A_REVB_REG_READ_NUM_REGS) {
                i2c_write(clock_enable_val);
            } else
                // set error LED
                if (i == 3) {
                has_error |= read_value & 0xEC; // Bits 8 7 6 _ 4 3 _ _ should trigger an alert (set low)
            } else
                if (i == 1) {
                has_error |= read_value ^ clock_enable_val;
            }

            i2c_stop();
        }
        gpio_set((uint8_t) ((!!has_error) << STATUS_ERROR_PIN));
        counter--;

        // Go into sleep mode if counter expires or status is reporting no issues
        if (!has_error | (counter == 0)) {
            SLEEP();
        }
    }
}

