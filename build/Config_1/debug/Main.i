# 1 "Main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 285 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Main.c" 2







#pragma config OSC = IntRC
#pragma config WDT = OFF
#pragma config CP = OFF
#pragma config MCLRE = ON





# 1 "./DFO-Registers.h" 1
# 25 "./DFO-Registers.h"
typedef struct
{
 unsigned char address;
 unsigned char value;

} si5351a_revb_register_t;

const unsigned char clock_enable_values[2] =
{
 0xFB,
 0xFE,
};

si5351a_revb_register_t const si5351a_revb_registers[(unsigned char)65] =
{
    { 0x03, 0xFF },
    { 0x10, 0x8C },
 { 0x11, 0x8C },
 { 0x12, 0x8C },
 { 0x13, 0x8C },
 { 0x14, 0x8C },
 { 0x15, 0x8C },
 { 0x16, 0x8C },
 { 0x17, 0x80 },
 { 0x02, 0x53 },
 { 0x04, 0x20 },
 { 0x07, 0x01 },
 { 0x0F, 0x00 },
 { 0x10, 0x0F },
 { 0x11, 0x8C },
 { 0x12, 0x0F },
 { 0x13, 0x8C },
 { 0x14, 0x8C },
 { 0x15, 0x8C },
 { 0x16, 0x8C },
 { 0x18, 0xBA },
 { 0x17, 0x8C },
 { 0x1A, 0xE8 },
 { 0x1B, 0x48 },
 { 0x1C, 0x00 },
 { 0x1D, 0x0F },
 { 0x1E, 0xBC },
 { 0x1F, 0x10 },
 { 0x20, 0x0C },
 { 0x21, 0xA0 },
 { 0x2A, 0xEC },
 { 0x2B, 0x85 },
 { 0x2C, 0x00 },
 { 0x2D, 0x79 },
 { 0x2E, 0xDC },
 { 0x2F, 0xA1 },
 { 0x30, 0x52 },
 { 0x31, 0xB4 },
 { 0x3A, 0x00 },
 { 0x3B, 0x01 },
 { 0x3C, 0x00 },
 { 0x3D, 0x62 },
 { 0x3E, 0x00 },
 { 0x3F, 0x00 },
 { 0x40, 0x00 },
 { 0x41, 0x00 },
 { 0x5A, 0x00 },
 { 0x5B, 0x00 },
 { 0x95, 0x00 },
 { 0x96, 0x00 },
 { 0x97, 0x00 },
 { 0x98, 0x00 },
 { 0x99, 0x00 },
 { 0x9A, 0x00 },
 { 0x9B, 0x00 },
 { 0xA2, 0x00 },
 { 0xA3, 0x00 },
 { 0xA4, 0x00 },
 { 0xA5, 0x00 },
 { 0xA7, 0x00 },
 { 0xBB, 0xD0 },
 { 0xB7, 0xD2 },
    { 0x01, 0x00 },
    { 0xB1, 0xA0 },
    { 0x03, 0xFF },
};
# 18 "Main.c" 2
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 1 3
# 18 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);


# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/xc8debug.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3





# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/features.h" 1 3
# 11 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3
# 21 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 1 3
# 24 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 128 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 174 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 22 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);



double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);





unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);
# 55 "/opt/microchip/xc8/v3.00/pic/include/c99/stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);




typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;




div_t div (int, int);
ldiv_t ldiv (long, long);




typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 5 "/opt/microchip/xc8/v3.00/pic/include/c99/xc8debug.h" 2 3







#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 24 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 2 3
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/builtins.h" 1 3



# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 1 3
# 26 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 1 3
# 133 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef short intptr_t;
# 164 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 179 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef long int32_t;
# 192 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef int32_t intmax_t;







typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 215 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uint32_t;
# 233 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/alltypes.h" 3
typedef uint32_t uintmax_t;
# 27 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;




typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;




typedef uint8_t uint_fast8_t;




typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;
# 148 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v3.00/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "/opt/microchip/xc8/v3.00/pic/include/c99/stdint.h" 2 3
# 5 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/builtins.h" 2 3


#pragma intrinsic(__nop)
extern void __nop(void);


#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);
# 25 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 2 3



# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 1 3




# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/htc.h" 1 3



# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 1 3
# 5 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/htc.h" 2 3
# 6 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 2 3







# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic_chip_select.h" 1 3
# 124 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic_chip_select.h" 3
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 1 3
# 45 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/__at.h" 1 3
# 46 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 2 3







extern volatile unsigned char INDF __attribute__((address(0x000)));

__asm("INDF equ 00h");


typedef union {
    struct {
        unsigned INDF :8;
    };
} INDFbits_t;
extern volatile INDFbits_t INDFbits __attribute__((address(0x000)));
# 73 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char TMR0 __attribute__((address(0x001)));

__asm("TMR0 equ 01h");


typedef union {
    struct {
        unsigned TMR0 :8;
    };
} TMR0bits_t;
extern volatile TMR0bits_t TMR0bits __attribute__((address(0x001)));
# 93 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char PCL __attribute__((address(0x002)));

__asm("PCL equ 02h");


typedef union {
    struct {
        unsigned PCL :8;
    };
} PCLbits_t;
extern volatile PCLbits_t PCLbits __attribute__((address(0x002)));
# 113 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char STATUS __attribute__((address(0x003)));

__asm("STATUS equ 03h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned :2;
        unsigned GPWUF :1;
    };
    struct {
        unsigned :5;
        unsigned PA0 :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0x003)));
# 188 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char FSR __attribute__((address(0x004)));

__asm("FSR equ 04h");


typedef union {
    struct {
        unsigned FSR :8;
    };
} FSRbits_t;
extern volatile FSRbits_t FSRbits __attribute__((address(0x004)));
# 208 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char OSCCAL __attribute__((address(0x005)));

__asm("OSCCAL equ 05h");


typedef union {
    struct {
        unsigned :1;
        unsigned CAL :7;
    };
    struct {
        unsigned :1;
        unsigned CAL0 :1;
        unsigned CAL1 :1;
        unsigned CAL2 :1;
        unsigned CAL3 :1;
        unsigned CAL4 :1;
        unsigned CAL5 :1;
        unsigned CAL6 :1;
    };
} OSCCALbits_t;
extern volatile OSCCALbits_t OSCCALbits __attribute__((address(0x005)));
# 274 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile unsigned char GPIO __attribute__((address(0x006)));

__asm("GPIO equ 06h");


typedef union {
    struct {
        unsigned GP0 :1;
        unsigned GP1 :1;
        unsigned GP2 :1;
        unsigned GP3 :1;
        unsigned GP4 :1;
        unsigned GP5 :1;
    };
} GPIObits_t;
extern volatile GPIObits_t GPIObits __attribute__((address(0x006)));
# 324 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile __control unsigned char OPTION __attribute__((address(0x000)));



extern volatile __control unsigned char TRIS __attribute__((address(0x006)));



extern volatile __control unsigned char TRISGPIO __attribute__((address(0x006)));
# 359 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/proc/pic12f508.h" 3
extern volatile __bit CAL0 __attribute__((address(0x29)));


extern volatile __bit CAL1 __attribute__((address(0x2A)));


extern volatile __bit CAL2 __attribute__((address(0x2B)));


extern volatile __bit CAL3 __attribute__((address(0x2C)));


extern volatile __bit CAL4 __attribute__((address(0x2D)));


extern volatile __bit CAL5 __attribute__((address(0x2E)));


extern volatile __bit CAL6 __attribute__((address(0x2F)));


extern volatile __bit CARRY __attribute__((address(0x18)));


extern volatile __bit DC __attribute__((address(0x19)));


extern volatile __bit GP0 __attribute__((address(0x30)));


extern volatile __bit GP1 __attribute__((address(0x31)));


extern volatile __bit GP2 __attribute__((address(0x32)));


extern volatile __bit GP3 __attribute__((address(0x33)));


extern volatile __bit GP4 __attribute__((address(0x34)));


extern volatile __bit GP5 __attribute__((address(0x35)));


extern volatile __bit GPWUF __attribute__((address(0x1F)));


extern volatile __bit PA0 __attribute__((address(0x1D)));


extern volatile __bit ZERO __attribute__((address(0x1A)));


extern volatile __bit nPD __attribute__((address(0x1B)));


extern volatile __bit nTO __attribute__((address(0x1C)));
# 125 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic_chip_select.h" 2 3
# 14 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 2 3
# 76 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 3
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);


# 1 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/eeprom_routines.h" 1 3
# 84 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 2 3
# 118 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/pic.h" 3
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;
# 29 "/opt/microchip/mplabx/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8/pic/include/xc.h" 2 3
# 19 "Main.c" 2


static volatile uint8_t GPIO_SHADOW;
static volatile uint8_t STATUS_REG = 0x0F;
static volatile uint8_t SDA_SHADOW = 0x01;
# 47 "Main.c"
void i2c_set(uint8_t mask) {
    TRIS = 0x0F & ~((mask & (1<< 0)) | ((SDA_SHADOW & 1) << 1));
    (_delay((unsigned long)((20)*(4000000/4000000.0))));
    do {
    SDA_SHADOW = (mask >> 1) & 1;
    TRIS = 0x0F & ~(mask);
    (_delay((unsigned long)((20)*(4000000/4000000.0))));
    } while (0);

}

void gpio_set(uint8_t mask) {

    GPIO_SHADOW = 0x30 & ~(mask);
    GPIO = GPIO_SHADOW;
}

void status_reg_set(uint8_t mask) {

    STATUS_REG |= mask;
}

void status_reg_clr(uint8_t mask) {

    STATUS_REG &= ~mask;
}
void i2c_start(void) {

    i2c_set(0x00);
    i2c_set(0x01 << 1);
}

void i2c_stop(void) {


    i2c_set(0x01 << 0 | 0x01 << 1);
    i2c_set(0x00);
}

void ACK() {


    i2c_set(0x01 << 0);
    i2c_set(0x00);

    status_reg_clr((uint8_t)(((GPIO & (uint8_t)(1 << 1)) != 0) << 2));
}
uint8_t i2c_write(unsigned char byte) {

    uint8_t result = 0x0;



     for (uint8_t i = 8; i > 0; i--) {
         byte = (uint8_t)(byte << 1u) | (uint8_t)(byte >> 7u);

        i2c_set((1 << 0) | ((byte & 1) == 0) << 1);

        i2c_set(((byte & 1) == 0) << 1);

    while(((GPIO & (1<<0)) == 0) & (STATUS_REG < 0xE0)) {
        _delay((unsigned long)((1)*(4000000/4000.0)));
        STATUS_REG = (STATUS_REG + 0x10);
        }
        status_reg_clr(0xF0);
        result = (uint8_t) (result << 1) | (GPIO & (1<<1));
     }

    return result;
}


void main(void) {






    TRIS = 0x0F;
    SDA_SHADOW = 0x0;
    gpio_set(0x0);




    OPTION = 0x4f;
    OSCCAL = 0x2A;


    status_reg_clr((GPIO & (1 << 2)) == 0 << 0);


    for (uint8_t i = 0; i < 65; i++) {

        i2c_start();
        i2c_write(0x60 << 1);
        ACK();
        i2c_write(si5351a_revb_registers[i].address);
        ACK();
        if (i == 65 -1) {

        _delay((unsigned long)((50)*(4000000/4000.0)));
            i2c_write(clock_enable_values[!!(STATUS_REG & (1 << 0))]);
        } else {
            i2c_write(si5351a_revb_registers[i].value);
        }
        ACK();
        i2c_stop();
        if((STATUS_REG & (1 << 2)) == 0) {
            if((STATUS_REG & (1 << 3)) == 0) {
                break;
            }
                status_reg_clr(1 << 3);
                status_reg_set((1 << 2));
                i--;
            } else {
                status_reg_set(1 << 3);
            }
        }



        i2c_start();
        i2c_write(0x60 << 1);
        ACK();
        i2c_write(0x00);
        ACK();
        i2c_stop();

    i2c_start();
        i2c_write(0x60 << 1 | 1);
        ACK();
        uint8_t status_read = i2c_write(0x0) != 0x11;
        status_reg_set(1 << 1);
        status_reg_clr((uint8_t)(status_read << 1));
        ACK();
        i2c_stop();

        uint8_t statusByte = STATUS_REG;
    while(1) {
            statusByte = ((uint8_t)(statusByte << 1u) | (uint8_t)(statusByte >> 7u));
            gpio_set((uint8_t)(((statusByte & 1) == 1) << 5) | 1 << 4);
        _delay((unsigned long)((500)*(4000000/4000.0)));
            gpio_set(0x0);
        _delay((unsigned long)((200)*(4000000/4000.0)));
        if (statusByte == STATUS_REG) {
       _delay((unsigned long)((1000)*(4000000/4000.0)));
        }

    }
}
