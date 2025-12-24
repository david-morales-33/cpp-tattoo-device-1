#pragma once
#include <core/presets/interfaces/presets_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/device_boot_presets.h>
#include <core/presets/data_transfer_objects/device_activation_presets.h>
#include <core/presets/data_transfer_objects/device_voltage_presets.h>
#include <core/presets/data_transfer_objects/device_voltage_list_presets.h>
#include <core/presets/data_transfer_objects/presets_list.h>

class PresetsRepositoryImpl : public IPresetsRepository
{
private:
    IDataProvider<DeviceBootPresets, PresetsList> &device_boot_provider;
    IDataProvider<DeviceActivationPresets, PresetsList> &device_activation_provider;
    IDataProvider<DeviceVoltagePresets, PresetsList> &voltage_provider;
    PresetsList data;

public:
    explicit PresetsRepositoryImpl(
        IDataProvider<DeviceBootPresets, PresetsList> &_device_boot_provider,
        IDataProvider<DeviceActivationPresets, PresetsList> &_device_activation_provider,
        IDataProvider<DeviceVoltagePresets, PresetsList> &_voltage_provider) : device_boot_provider(_device_boot_provider),
                                                                               device_activation_provider(_device_activation_provider),
                                                                               voltage_provider(_voltage_provider) {}
    void load() { data = voltage_provider.get(); }
    void updateVoltage(DeviceVoltagePresets voltage) override
    {
        if (data.saveVoltage(voltage))
            voltage_provider.persist(voltage);
    }
    void updateDeviceBoot(DeviceBootPresets boot) override
    {
        if (data.updateDeviceBoot(boot))
            device_boot_provider.persist(boot);
    }
    void updateDeviceActivation(DeviceActivationPresets activation) override
    {
        if (data.updateDeviceActivation(activation))
            device_activation_provider.persist(activation);
    }
    const PresetsList &getPresets() const override { return data; }
};