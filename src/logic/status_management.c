
#include "../headers/constants.h"
#include "../headers/status_management.h"

#define STATUS_REG_SET(mask)          \
    do {                              \
        status_reg |= (unsigned char) mask; \
    } while(0)

#define STATUS_REG_CLR(mask)                \
    do {                                    \
    status_reg &= ~((unsigned char) mask);  \
    } while(0)

void status_reg_set(unsigned char mask) {
    STATUS_REG_SET(mask);
}

void status_reg_clr(unsigned char mask) {
    STATUS_REG_CLR(mask);
}