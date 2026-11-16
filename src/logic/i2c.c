#include "../headers/constants.h"
#include "../headers/i2c.h"
#include "../headers/pic_functions.h"
#include "../headers/status_management.h"
#ifdef __delay_us
#define WAIT() (__delay_us(10))
#else
#define WAIT() (sda_shadow = sda_shadow)
#endif

#define ACK()                       \
    do {                            \
        i2c_set(0x01 << SCL_PIN);   \
        i2c_set(0x00);              \
    } while(0)

void i2c_set(unsigned char mask) {
    TRIS = TRIS_DEFAULT & ~((mask & (1 << SCL_PIN)) | ((sda_shadow & 1) << SDA_PIN));
    WAIT();
    do {
        sda_shadow = (mask >> SDA_PIN) & 1;
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

void i2c_ack(void) {
    ACK();
}

unsigned char i2c_write(unsigned char byte) {

    unsigned char result = 0x0;
    // For each of 8 bits: set SDA, pulse SCL high then low
    // Then read ACK

    for (unsigned char i = 8; i > 0; i--) {
        byte = (unsigned char) (byte << 1u) | (unsigned char) (byte >> 7u);
        // Invert the bit to pull down when 0
        i2c_set((unsigned char) ((1 << SCL_PIN) | ((byte & 1) == 0) << SDA_PIN));

        i2c_set((unsigned char) (((byte & 1) == 0) << SDA_PIN));
        //wait for clock stretching
        while (((GPIO & (1 << SCL_PIN)) == 0) & (status_reg < 0xE0)) {
            WAIT();
            status_reg = (status_reg + 0x10);
        }
        status_reg_clr(0xF0);
        result = ((unsigned char) (result << 1) | (unsigned char) (GPIO >> SDA_PIN)); // SDA happens to be the last pin conveniently
        gpio_set((unsigned char) ((result ^ 1 & 1) << STATUS_ERROR_PIN));
    }
    ACK();

    return result;
}