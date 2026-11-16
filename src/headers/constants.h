#ifndef CONSTANTS
#define CONSTANTS
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
#define GPIO_DEFAULT 0xCF
//OPTION GPWU | GPPU | T0CS | T0SE | PSA | PS2 | PS1 | PS0
#define OPTION_DEFAULT 0x0F
#endif