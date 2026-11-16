#ifndef I2C
#define I2C
static volatile unsigned char sda_shadow = 0x01;
void i2c_start(void); // SDA high, SCL high, then SDA low (while SCL high)
void i2c_stop(void); // SDA low, SCL high, then SDA high (while SCL high)
void i2c_set(unsigned char mask);
void i2c_ack(void); 
unsigned char i2c_write(unsigned char byte);

#endif
#ifndef _XC_H_
#define _XC_H_
extern volatile __control unsigned char TRIS ;
extern volatile unsigned char           GPIO;
#endif