#pragma once
#include <array>
#include <core/presets/data_transfer_objects/voltage.h>
#include <core/presets/data_transfer_objects/voltage_list.h>
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/device_boot.h>
#include <core/presets/interfaces/device_activation.h>

class Presets
{
private:
    MachineType type;
    DeviceBoot boot;
    DeviceActivation activation;
    VoltageList voltage_list;

public:
    Presets(
        MachineType _type,
        DeviceBoot _boot,
        DeviceActivation _activation,
        VoltageList _voltage_list)
        : type(_type),
          boot(_boot),
          activation(_activation),
          voltage_list(_voltage_list) {}

    Presets(MachineType _type)
        : type(_type), voltage_list() {}

    MachineType getType() const { return type; }
    DeviceBoot getBoot() const { return boot; }
    DeviceActivation getActivation() const { return activation; }
    const VoltageList &getVoltageList()const { return voltage_list; }
    VoltageList &getVoltageList() { return voltage_list; }

    bool setBoot(DeviceBoot _boot)
    {
        if (boot == _boot)
            return false;
        boot = _boot;
        return true;
    }
    bool setActivation(DeviceActivation _activation)
    {
        if (activation == _activation)
            return false;
        activation = _activation;
        return true;
    }
};
