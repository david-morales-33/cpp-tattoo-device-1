#pragma once
#include <array>

#include <core/device_configuration/data_transfer_objects/voltage.h>

class VoltageGroup
{
private:
    VoltageType type;
    std::array<Voltage, 4> voltages;

public:
    VoltageGroup(VoltageType _type)
        : type(_type), voltages{
                           Voltage{VALUE_1, _type, 0},
                           Voltage{VALUE_2, _type, 0},
                           Voltage{VALUE_3, _type, 0},
                           Voltage{VALUE_4, _type, 0}} {}

    const std::array<Voltage, 4> &getAll() const { return voltages; }
    Voltage &operator[](int index) { return voltages[index]; }
};
