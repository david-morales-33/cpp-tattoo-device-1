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
                           Voltage{VoltageElement::VALUE_1, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_2, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_3, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_4, _type, 0.0f}} {}
    VoltageGroup() {}

    const std::array<Voltage, 4> &getAll() const { return voltages; }
    const VoltageType &getType() const { return type; }

    Voltage &operator[](int index) { return voltages[index]; }

    bool updateByIndex(int index, float newValue)
    {
        if (index < 0 || index >= voltages.size())
        {
            return false;
        }
        voltages[index].setValue(newValue);
        return true;
    }
};
