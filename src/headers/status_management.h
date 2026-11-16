#ifndef STATUS_MANAGEMENT
#define STATUS_MANAGEMENT
extern volatile unsigned char status_reg;
void status_reg_set(unsigned char mask);
void status_reg_clr(unsigned char mask);
#endif