
#include "../include/Alarm.h"

Alarm::Alarm()
    : m_sensor(&m_defaultSensor),
      m_lowPressureThreshold(17),
      m_highPressureThreshold(21),
      m_alarmOn(false)
{
}

Alarm::Alarm(ISensor& sensor)
    : m_sensor(&sensor),
      m_lowPressureThreshold(17),
      m_highPressureThreshold(21),
      m_alarmOn(false)
{
}

void Alarm::check()
{
    double psiPressureValue = m_sensor->popNextPressurePsiValue();

    if (psiPressureValue < m_lowPressureThreshold ||
        psiPressureValue > m_highPressureThreshold)
    {
        m_alarmOn = true;
    }
}

bool Alarm::isAlarmOn()
{
    return m_alarmOn;
}
