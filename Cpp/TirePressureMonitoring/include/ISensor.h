#pragma once

class ISensor
{
public:
    virtual ~ISensor() = default;

    virtual double popNextPressurePsiValue() = 0;
};