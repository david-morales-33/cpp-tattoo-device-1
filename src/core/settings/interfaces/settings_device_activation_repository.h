#pragma once
#include <core/settings/interfaces/physical_device_activation.h>
#include <core/settings/interfaces/remote_device_activation.h>

class ISettingsDeviceActivationRepository
{
public:
    virtual void updatePhysicalDeviceActivation(PhysicalDeviceActivation activation) = 0;
    virtual void updateRemoteDeviceActivation(RemoteDeviceActivation activation) = 0;

    virtual PhysicalDeviceActivation getPhysicalDeviceActivation() = 0;
    virtual RemoteDeviceActivation getRemoteDeviceActivation() = 0;

    virtual ~ISettingsDeviceActivationRepository() {}
};