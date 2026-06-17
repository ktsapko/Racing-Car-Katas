#pragma once

#include "ISensor.h"

class Sensor : public ISensor
{
public:
    Sensor();

    double popNextPressurePsiValue() override;
};