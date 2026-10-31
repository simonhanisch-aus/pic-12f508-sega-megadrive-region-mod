/*
 * Si5351A Rev B Configuration Register Export Header File
 *
 * This file represents a series of Skyworks Si5351A Rev B 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Skyworks ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5351A Rev B
 * Design ID:                                          
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v4.19 [2026-07-23]
 * Timestamp:                                          2026-08-21 14:52:24 GMT+09:30
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5351A_REVB_REG_CONFIG_HEADER
#define SI5351A_REVB_REG_CONFIG_HEADER
#define SI5351A_REVB_REG_CONFIG_NUM_REGS 74
#define clock_enable_reg 0x03
#define SI5351A_REVB_REG_READ_NUM_REGS 5
#define SI5351_ADDR 0x60 << 1   // 0x60 << 1 (write mode)
#define SI5351_ADDR_READ SI5351_ADDR | 1   // (0x60 << 1 | 1)  (read mode)

const unsigned char clock_enable_values[3] ={
    0xFB, //PAL
    0xFE, //NTSC 
    0xFC //NTSC 4.43
};
const unsigned char si5351a_revb_read_registers[SI5351A_REVB_REG_READ_NUM_REGS] ={
    0x00, //read
    clock_enable_reg, //Clock enable read
    0x00, //read
    0x00, //Status
    clock_enable_reg //Clock enable set
};
const unsigned char si5351a_revb_read_addresses[SI5351A_REVB_REG_READ_NUM_REGS] ={
    SI5351_ADDR_READ,
    SI5351_ADDR, //Clock enable read
    SI5351_ADDR_READ,
    SI5351_ADDR, //Status 
    SI5351_ADDR //Clock enable set
};
const unsigned char si5351a_revb_registers[SI5351A_REVB_REG_CONFIG_NUM_REGS] ={
    0x02, //set interrupt masks
    0x03, // disable outputs
    0x04,
    0x07,
    0x0F,
    0x10, // power down output drivers
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16,
    0x17, // END PRE-CONFIG
    0x18,
    0x1A,
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A,
    0x3B,
    0x3C,
    0x3D,
    0x3E,
    0x3F,
    0x40,
    0x41,
    0x5A,
    0x5B,
    0x95,
    0x96,
    0x97,
    0x98,
    0x99,
    0x9A,
    0x9B,
    0xA2,
    0xA3,
    0xA4,
    0xA5,
    0xA6,
    0xA7,
    0xB7, //load capacitor selection (01 6pF | 10 8pF | 11 10 pF) END CONFIG
    0x01, // reset status flags
    0xB1, // reset PLLs END POST CONFIG
};

const unsigned char si5351a_revb_registers_values[SI5351A_REVB_REG_CONFIG_NUM_REGS] ={
    0x53, //set interrupt masks
    0xFF, // disable outputs
    0x20,
    0x01,
    0x00,
    0x0F, // power down output drivers
    0x2F,
    0x2F,
    0x8C,
    0x8C,
    0x8C,
    0x8C,
    0x8C, // END PRE-CONFIG
    0x2A,
    0xE8,
    0x48,
    0x00,
    0x0F,
    0xBC,
    0x10,
    0x0C,
    0xA0,
    0xF5,
    0xE1,
    0x00,
    0x0F,
    0x06,
    0x52,
    0x87,
    0xBA,
    0xEC,
    0x85,
    0x00,
    0x06,
    0x41,
    0xA9,
    0x8E,
    0x3B,
    0x00,
    0x01,
    0x00,
    0x62,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x00,
    0x06,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x92, //load capacitor selection (01 6pF | 10 8pF | 11 10 pF) END CONFIG
    0x00, // reset status flags
    0xA0 // reset PLLs END POST CONFIG
};

/*
 * Design Report
 *
 * Overview
 * ========
 * 
 * Part:               Si5351A
 * Created By:         ClockBuilder Pro v4.19 [2026-07-23]
 * Timestamp:          2026-10-26 19:21:28 GMT+10:30
 * 
 * Design Rule Check
 * =================
 * 
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - OUT0 [53.693175 MHz] and OUT1 [4.433619 MHz] may have coupling [1]
 * - OUT0 [53.693175 MHz] and OUT2 [53.203424 MHz] may have coupling [1]
 * - OUT1 [4.433619 MHz] and OUT2 [53.203424 MHz] may have coupling [1]
 * - The desired configuration is too large to fit into NVM for a factory
 *   Programmed part. You can, however, still export the configuration and
 *   program the part through I2C.
 * 
 * Footnotes:
 * [1] To avoid coupling between outputs, Skyworks recommends the following:
 * 
 * - Avoid adjacent frequency values that are close to each other.
 * - Adjacent frequency values that are integer multiples of one another are okay
 *   and these outputs should be grouped accordingly.
 * - Unused outputs can be used to separate clock outputs that might otherwise
 *   interfere with one another.
 * - CBPro uses an clock's integration bandwidth (IBW) to determine whether two
 *   adjacent frequencies are too close. An IBW of 20 MHz is used for frequencies
 *   80 MHz and larger. Lower frequencies will use IBW of OUT/4. CBPro will flag
 *   fundamental coupling and coupling up to the fourth harmonic, where coupling
 *   frequency = Absolute(OUTa*x - OUTb*y) for all combinations of x and y 1
 *   through 4. If any one of these values is less than or equal to the IBW, the
 *   clock is flagged as having possible coupling.
 * 
 * Skyworks recommends you validate your design's jitter performance using an Evaluation Board.
 * 
 * Design
 * ======
 * I2C Address: 0x60
 * 
 * Inputs:
 *     IN0: 25 MHz
 * 
 * Outputs:
 *    OUT0: 53.693175 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT1: 4.433619 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT2: 53.203424 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 * 
 * Frequency Plan
 * ==============
 * 
 * PLL_A:
 *    Enabled Features = None
 *    Fvco             = 886.7238 MHz
 *    M                = 35.468952
 *    Input0:
 *       Source           = Crystal
 *       Source Frequency = 25 MHz
 *       Fpfd             = 25 MHz
 *       Load Capacitance = Load_08pF
 *    Output0:
 *       Features       = None
 *       Disabled State = HiZ
 *       R              = 1  (2^0)
 *       Fout           = 53.693175 MHz (NTSC Main OSC)
 *       N              = 16.5146464145582748... [ 16 + 368440/715909 ]
 *    Output1:
 *       Features       = None
 *       Disabled State = HiZ
 *       R              = 1  (2^0)
 *       Fout           = 4.433619 MHz (For NTSC 4.43)
 *       N              = 200
 * PLL_B:
 *    Enabled Features = None
 *    Fvco             = 851.254784 MHz
 *    M                = 34.05019136
 *    Input0:
 *       Source           = Crystal
 *       Source Frequency = 25 MHz
 *       Fpfd             = 25 MHz
 *       Load Capacitance = Load_08pF
 *    Output2:
 *       Features       = None
 *       Disabled State = HiZ
 *       R              = 1  (2^0)
 *       Fout           = 53.203424 MHz (PAL Main OSC)
 *       N              = 16
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name    Decimal Value      Hex Value        
 * ------------  --------------  -----------------  -----------------
 * 0x02[3]     XO_LOS_MASK     0                  0x0              
 * 0x02[4]     CLK_LOS_MASK    1                  0x1              
 * 0x02[5]     LOL_A_MASK      0                  0x0              
 * 0x02[6]     LOL_B_MASK      0                  0x0              
 * 0x02[7]     SYS_INIT_MASK   0                  0x0              
 * 0x03[7:0]   CLK_OEB         7                  0x07             
 * 0x04[4]     DIS_RESET_LOLA  0                  0x0              
 * 0x04[5]     DIS_RESET_LOLB  0                  0x0              
 * 0x07[7:4]   I2C_ADDR_CTRL   0                  0x0              
 * 0x0F[2]     PLLA_SRC        0                  0x0              
 * 0x0F[3]     PLLB_SRC        0                  0x0              
 * 0x0F[4]     PLLA_INSELB     0                  0x0              
 * 0x0F[5]     PLLB_INSELB     0                  0x0              
 * 0x0F[7:6]   CLKIN_DIV       0                  0x0              
 * 0x10[1:0]   CLK0_IDRV       3                  0x3              
 * 0x10[3:2]   CLK0_SRC        3                  0x3              
 * 0x10[4]     CLK0_INV        0                  0x0              
 * 0x10[5]     MS0_SRC         0                  0x0              
 * 0x10[6]     MS0_INT         0                  0x0              
 * 0x10[7]     CLK0_PDN        0                  0x0              
 * 0x11[1:0]   CLK1_IDRV       3                  0x3              
 * 0x11[3:2]   CLK1_SRC        3                  0x3              
 * 0x11[4]     CLK1_INV        0                  0x0              
 * 0x11[5]     MS1_SRC         0                  0x0              
 * 0x11[6]     MS1_INT         0                  0x0              
 * 0x11[7]     CLK1_PDN        0                  0x0              
 * 0x12[1:0]   CLK2_IDRV       3                  0x3              
 * 0x12[3:2]   CLK2_SRC        3                  0x3              
 * 0x12[4]     CLK2_INV        0                  0x0              
 * 0x12[5]     MS2_SRC         1                  0x1              
 * 0x12[6]     MS2_INT         0                  0x0              
 * 0x12[7]     CLK2_PDN        0                  0x0              
 * 0x13[1:0]   CLK3_IDRV       0                  0x0              
 * 0x13[3:2]   CLK3_SRC        3                  0x3              
 * 0x13[4]     CLK3_INV        0                  0x0              
 * 0x13[5]     MS3_SRC         0                  0x0              
 * 0x13[6]     MS3_INT         0                  0x0              
 * 0x13[7]     CLK3_PDN        1                  0x1              
 * 0x14[1:0]   CLK4_IDRV       0                  0x0              
 * 0x14[3:2]   CLK4_SRC        3                  0x3              
 * 0x14[4]     CLK4_INV        0                  0x0              
 * 0x14[5]     MS4_SRC         0                  0x0              
 * 0x14[6]     MS4_INT         0                  0x0              
 * 0x14[7]     CLK4_PDN        1                  0x1              
 * 0x15[1:0]   CLK5_IDRV       0                  0x0              
 * 0x15[3:2]   CLK5_SRC        3                  0x3              
 * 0x15[4]     CLK5_INV        0                  0x0              
 * 0x15[5]     MS5_SRC         0                  0x0              
 * 0x15[6]     MS5_INT         0                  0x0              
 * 0x15[7]     CLK5_PDN        1                  0x1              
 * 0x16[1:0]   CLK6_IDRV       0                  0x0              
 * 0x16[3:2]   CLK6_SRC        3                  0x3              
 * 0x16[4]     CLK6_INV        0                  0x0              
 * 0x16[5]     MS6_SRC         0                  0x0              
 * 0x16[6]     FBA_INT         0                  0x0              
 * 0x16[7]     CLK6_PDN        1                  0x1              
 * 0x17[1:0]   CLK7_IDRV       0                  0x0              
 * 0x17[3:2]   CLK7_SRC        3                  0x3              
 * 0x17[4]     CLK7_INV        0                  0x0              
 * 0x17[5]     MS7_SRC         0                  0x0              
 * 0x17[6]     FBB_INT         0                  0x0              
 * 0x17[7]     CLK7_PDN        1                  0x1              
 * 0x18[1:0]   CLK0_DIS_STATE  2                  0x2              
 * 0x18[3:2]   CLK1_DIS_STATE  2                  0x2              
 * 0x18[5:4]   CLK2_DIS_STATE  2                  0x2              
 * 0x1C[17:0]  MSNA_P1         4028               0xFBC          
 * 0x1F[19:0]  MSNA_P2         3232               0xCA0          
 * 0x1F[23:4]  MSNA_P3         125000             0x1E848          
 * 0x24[17:0]  MSNB_P1         3846               0xF06          
 * 0x27[19:0]  MSNB_P2         165818             0x287BA          
 * 0x27[23:4]  MSNB_P3         390625             0x5F5E1          
 * 0x2C[17:0]  MS0_P1          1601               0x641          
 * 0x2F[19:0]  MS0_P2          626235             0x098E3B         
 * 0x2F[23:4]  MS0_P3          715909             0x0AEC85         
 * 0x34[17:0]  MS1_P1          25088              0x06200          
 * 0x37[19:0]  MS1_P2          0                  0x000          
 * 0x37[23:4]  MS1_P3          1                  0x001          
 * 0x3C[17:0]  MS2_P1          1536               0x600          
 * 0x3F[19:0]  MS2_P2          0                  0x000          
 * 0x3F[23:4]  MS2_P3          1                  0x001          
 * 0x5A[7:0]   MS6_P1          0                  0x00             
 * 0x5B[7:0]   MS7_P1          0                  0x00             
 * 0x95[14:0]  SSDN_P2         0                  0x00           
 * 0x95[7]     SSC_EN          0                  0x0              
 * 0x97[14:0]  SSDN_P3         0                  0x00           
 * 0x97[7]     SSC_MODE        0                  0x0              
 * 0x99[11:0]  SSDN_P1         0                  0x00            
 * 0x9A[15:4]  SSUDP           0                  0x00            
 * 0xA2[21:0]  VCXO_PARAM      0                  0x00         
 * 0xA5[7:0]   CLK0_PHOFF      0                  0x00             
 * 0xA6[7:0]   CLK1_PHOFF      0                  0x00             
 * 0xA7[7:0]   CLK2_PHOFF      0                  0x00             
 * 0xB7[7:6]   XTAL_CL         2                  0x2
 * 
 *
 */

#endif