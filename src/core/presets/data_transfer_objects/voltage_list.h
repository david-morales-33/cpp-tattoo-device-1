#pragma once
#include <array>
#include <core/presets/data_transfer_objects/voltage.h>
#include <core/presets/data_transfer_objects/device_voltage_presets.h>

class VoltageList
{
private:
    std::array<Voltage, 4> data;
public:
    VoltageList(MachineType _type)
        : data{
              Voltage{VoltageElement::VALUE_1, 0.0f},
              Voltage{VoltageElement::VALUE_2, 0.0f},
              Voltage{VoltageElement::VALUE_3, 0.0f},
              Voltage{VoltageElement::VALUE_4, 0.0f}} {}

    const std::array<Voltage, 4> &getData() const { return data; }

    bool updateVoltage(DeviceVoltagePresets voltage)
    {
        int index = static_cast<int>(voltage.getElement());
        if (voltage.getValue() == data[index].getValue())
            return false;

        data[index].setValue(voltage.getValue());
        return true;
    }
};