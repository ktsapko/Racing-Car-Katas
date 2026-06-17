#include <gtest/gtest.h>

#include "Alarm.h"
#include "ISensor.h"

class FakeSensor : public ISensor
{
public:
  explicit FakeSensor(double value)
      : m_value(value)
  {
  }

  double popNextPressurePsiValue() override
  {
    return m_value;
  }

private:
  double m_value;
};

TEST(Alarm, TurnsOnWhenPressureTooLow)
{
  FakeSensor sensor(16.0);

  Alarm alarm(sensor);

  alarm.check();

  EXPECT_TRUE(alarm.isAlarmOn());
}

TEST(Alarm, TurnsOnWhenPressureTooHigh)
{
  FakeSensor sensor(22.0);

  Alarm alarm(sensor);

  alarm.check();

  EXPECT_TRUE(alarm.isAlarmOn());
}

TEST(Alarm, StaysOffWhenPressureIsNormal)
{
  FakeSensor sensor(19.0);

  Alarm alarm(sensor);

  alarm.check();

  EXPECT_FALSE(alarm.isAlarmOn());
}
