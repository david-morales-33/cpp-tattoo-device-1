#pragma once
#include <core/settings/interfaces/settings_device_activation_repository.h>
#include <core/shared/interfaces/data_provider.h>

class SettingsDeviceActivationRepositoryImpl : public ISettingsDeviceActivationRepository
{
private:
    IDataProvider<RemoteDeviceActivation, RemoteDeviceActivation> &remote_device_provider;
    IDataProvider<PhysicalDeviceActivation, PhysicalDeviceActivation> &physical_device_provider;

public:
    explicit SettingsDeviceActivationRepositoryImpl(
        IDataProvider<RemoteDeviceActivation, RemoteDeviceActivation> &_remote_device_provider,
        IDataProvider<PhysicalDeviceActivation, PhysicalDeviceActivation> &_physical_device_provider) : remote_device_provider(_remote_device_provider),
                                                                                                        physical_device_provider(_physical_device_provider)
    {
    }
    void updatePhysicalDeviceActivation(PhysicalDeviceActivation activation) { physical_device_provider.persist(activation); }
    void updateRemoteDeviceActivation(RemoteDeviceActivation activation) { remote_device_provider.persist(activation); }

    PhysicalDeviceActivation getPhysicalDeviceActivation() { return physical_device_provider.get(); }
    RemoteDeviceActivation getRemoteDeviceActivation() { return remote_device_provider.get(); }
};