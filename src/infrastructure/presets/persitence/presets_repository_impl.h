#pragma once
#include <core/presets/interfaces/presets_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/shared/interfaces/listener.h>
#include <core/presets/data_transfer_objects/device_boot_presets.h>
#include <core/presets/data_transfer_objects/device_activation_presets.h>
#include <core/presets/data_transfer_objects/device_voltage_presets.h>
#include <core/presets/data_transfer_objects/device_voltage_list_presets.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/shared/data_transfer_objects/remote_device.h>

class PresetsRepositoryImpl : public IPresetsRepository
{
private:
    IDataProvider<DeviceBootPresets, PresetsList> &device_boot_provider;
    IDataProvider<DeviceActivationPresets, PresetsList> &device_activation_provider;
    IDataProvider<DeviceVoltagePresets, PresetsList> &voltage_provider;
    IDataProvider<RemoteDeviceMachine, PresetsList> &remote_devices_provider;
    IListener<std::vector<RemoteDevice>> &listener;

    PresetsList preset_data;

public:
    explicit PresetsRepositoryImpl(
        IDataProvider<DeviceBootPresets, PresetsList> &_device_boot_provider,
        IDataProvider<DeviceActivationPresets, PresetsList> &_device_activation_provider,
        IDataProvider<DeviceVoltagePresets, PresetsList> &_voltage_provider,
        IDataProvider<RemoteDeviceMachine, PresetsList> &_remote_devices_provider,
        IListener<std::vector<RemoteDevice>> &_listener) : device_boot_provider(_device_boot_provider),
                                                           device_activation_provider(_device_activation_provider),
                                                           voltage_provider(_voltage_provider),
                                                           remote_devices_provider(_remote_devices_provider),
                                                           listener(_listener) {}
    void load() { preset_data = voltage_provider.get(); }

    void updateVoltage(DeviceVoltagePresets voltage) override
    {
        if (preset_data.updateDeviceVoltage(voltage))
            voltage_provider.persist(voltage);
    }
    void updateDeviceBoot(DeviceBootPresets boot) override
    {
        if (preset_data.updateDeviceBoot(boot))
            device_boot_provider.persist(boot);
    }
    void updateDeviceActivation(DeviceActivationPresets activation) override
    {
        if (preset_data.updateDeviceActivation(activation))
            device_activation_provider.persist(activation);
    }
    void connect(RemoteDeviceMachine remote_device) override
    {
        if (preset_data.connectRemoteDevice(remote_device))
            remote_devices_provider.persist(remote_device);
    }
    void disconnect(RemoteDeviceMachine remote_device) override
    {
        if (preset_data.disconnectRemoteDevice(remote_device))
            remote_devices_provider.remove(remote_device);
    }
    const PresetsList &getPresets() const override { return preset_data; }
    const std::vector<RemoteDevice> &searchRemoteDevices() const override { return listener.listen(); }
};