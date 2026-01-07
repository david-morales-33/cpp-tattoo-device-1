#pragma once
#include <core/presets/data_transfer_objects/device_boot_presets.h>
#include <core/presets/data_transfer_objects/device_activation_presets.h>
#include <core/presets/data_transfer_objects/device_voltage_presets.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/presets/data_transfer_objects/remote_device_machine.h>
#include <core/presets/data_transfer_objects/connected_devices_List.h>
#include <core/shared/data_transfer_objects/remote_device.h>

class IPresetsRepository
{
public:
    virtual void updateVoltage(DeviceVoltagePresets voltage) = 0;
    virtual void updateDeviceBoot(DeviceBootPresets boot) = 0;
    virtual void updateDeviceActivation(DeviceActivationPresets activation) = 0;
    virtual void connect(RemoteDeviceMachine remote_device) = 0;
    virtual void disconnect(RemoteDeviceMachine remote_device) = 0;
    virtual const PresetsList &getPresets() const = 0;
    virtual const ConnectedDevicesList &getConnectedDevices() const = 0;
    virtual const std::vector<RemoteDevice> &searchRemoteDevices() const = 0;
    virtual ~IPresetsRepository() = default;
};