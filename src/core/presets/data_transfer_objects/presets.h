#pragma once
#include <array>
#include <core/presets/data_transfer_objects/voltage.h>
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/device_boot.h>
#include <core/presets/interfaces/device_activation.h>

class Presets
{
private:
    MachineType type;
    DeviceBoot boot;
    DeviceActivation activation;
    std::array<Voltage, 4> voltages;

public:
    Presets(MachineType _type,
            DeviceBoot _boot,
            DeviceActivation _activation)
        : type(_type), boot(_boot), activation(_activation), voltages{
                                                                 Voltage{VoltageElement::VALUE_1, _type, 0.0f},
                                                                 Voltage{VoltageElement::VALUE_2, _type, 0.0f},
                                                                 Voltage{VoltageElement::VALUE_3, _type, 0.0f},
                                                                 Voltage{VoltageElement::VALUE_4, _type, 0.0f}} {}
    Presets(MachineType _type)
        : type(_type), voltages{
                           Voltage{VoltageElement::VALUE_1, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_2, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_3, _type, 0.0f},
                           Voltage{VoltageElement::VALUE_4, _type, 0.0f}} {}

    MachineType getType() const { return type; }
    DeviceBoot getBoot() const { return boot; }
    DeviceActivation getActivation() const { return activation; }
    const std::array<Voltage, 4> &getVoltages() const { return voltages; }

    void setType(MachineType _type) { type = type; }
    void setBoot(DeviceBoot _boot) { boot = _boot; }
    void setActivation(DeviceActivation _activation) { activation = _activation; }
    bool updateVoltageByIndex(int index, float newValue)
    {
        if (index < 0 || index >= voltages.size())
        {
            return false;
        }
        voltages[index].setValue(newValue);
        return true;
    }
};
