#pragma once
#include <core/presets/interfaces/device_activation.h>
#include <core/shared/interfaces/machine_type.h>

class DeviceActivationPresets
{
private:
    MachineType type;
    DeviceActivation activation;

public:
    DeviceActivationPresets(MachineType _type,
                      DeviceActivation _activation) : type(_type), activation(_activation) {}

    MachineType getType() const { return type; }
    DeviceActivation getActivation() const { return activation; }
};