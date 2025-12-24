#pragma once
#include <array>
#include <core/presets/data_transfer_objects/voltage.h>

class DeviceVoltageListPresets
{
private:
    MachineType type;
    std::array<Voltage, 4> data;

public:
    DeviceVoltageListPresets(MachineType _type)
        : type(_type), data{
                           Voltage{VoltageElement::VALUE_1, 0.0f},
                           Voltage{VoltageElement::VALUE_2, 0.0f},
                           Voltage{VoltageElement::VALUE_3, 0.0f},
                           Voltage{VoltageElement::VALUE_4, 0.0f}} {}

    MachineType getType() const { return type; }
    const std::array<Voltage, 4> &getVoltages() const { return data; }
};