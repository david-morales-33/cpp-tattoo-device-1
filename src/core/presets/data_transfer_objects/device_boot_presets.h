#pragma once
#include <core/presets/interfaces/device_boot.h>
#include <core/shared/interfaces/machine_type.h>

class DeviceBootPresets
{
private:
    MachineType type;
    DeviceBoot boot;

public:
    DeviceBootPresets(MachineType _type,
                      DeviceBoot _boot) : type(_type), boot(_boot) {}

    MachineType getType() const { return type; }
    DeviceBoot getBoot() const { return boot; }
};