#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/remote_device_machine.h>

class PresetsRemoteDevicesTestProvider : public IDataProvider<RemoteDeviceMachine, PresetsList>
{
private:
    PresetsList data;

public:
    void persist(const RemoteDeviceMachine &remote_device) override { data.connectRemoteDevice(remote_device); }
    void remove(const RemoteDeviceMachine &remote_device) override { data.disconnectRemoteDevice(remote_device); }
    const PresetsList &get() const override { return data; }
};