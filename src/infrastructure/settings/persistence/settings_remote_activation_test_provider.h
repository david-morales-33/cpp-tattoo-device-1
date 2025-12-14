#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/settings/interfaces/remote_device_activation.h>

class SettingsRemoteActivationTestProvider : public IDataProvider<RemoteDeviceActivation, RemoteDeviceActivation>
{
private:
    RemoteDeviceActivation remote_activation = RemoteDeviceActivation::PULSES;

public:
    void persist(const RemoteDeviceActivation &data) override { remote_activation = data; }
    void load() override {}
    void reset() override { remote_activation = RemoteDeviceActivation::PULSES; }
    void remove(const RemoteDeviceActivation &data) override {}
    const RemoteDeviceActivation &get() const override { return remote_activation; }
};