#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/connected_devices_List.h>
#include <core/presets/data_transfer_objects/remote_device_machine.h>

class PresetsRemoteDevicesTestProvider : public IDataProvider<RemoteDeviceMachine, ConnectedDevicesList>
{
private:
    ConnectedDevicesList data;

public:
    void persist(const RemoteDeviceMachine &remote_device) override { data.save(remote_device); }
    const ConnectedDevicesList &get() const override { return data; }
};