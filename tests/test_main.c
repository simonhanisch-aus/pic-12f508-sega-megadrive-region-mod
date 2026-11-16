#include "unity.h"

void test_battery_percentage_clamps_at_100(void);
void test_battery_percentage_below_floor(void);

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_battery_percentage_clamps_at_100);
    RUN_TEST(test_battery_percentage_below_floor);
    return UNITY_END();
}