#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/presets/data_transfer_objects/voltage.h>

class PresetsBootTestProvider : public IDataProvider<DeviceActivationPresets, PresetsList>
{
private:
    PresetsList data;

public:
    void persist(const DeviceActivationPresets &device_activation) override { data.updateDeviceActivation(device_activation); }
    void load() override {}
    void reset() override {}
    void remove(const DeviceActivationPresets &device_activation) override {}
    const PresetsList &get() const override { return data; }
};