
#pragma once

#include "Sensor.h"
#include "ISensor.h"

class Alarm
{
public:
    Alarm();
    explicit Alarm(ISensor& sensor);

    void check();
    bool isAlarmOn();

private:
    ISensor* m_sensor;
    Sensor m_defaultSensor;

    double m_lowPressureThreshold;
    double m_highPressureThreshold;
    bool m_alarmOn;
};