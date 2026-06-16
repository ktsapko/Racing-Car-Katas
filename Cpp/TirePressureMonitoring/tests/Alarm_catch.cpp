#include <gtest/gtest.h>

TEST(Alarm, InitiallyOff)
{
    Alarm alarm;

    EXPECT_FALSE(alarm.isAlarmOn());
}