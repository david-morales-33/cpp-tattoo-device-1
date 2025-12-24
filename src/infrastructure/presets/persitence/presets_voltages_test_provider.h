#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/presets/data_transfer_objects/voltage.h>

class PresetsVoltageTestProvider : public IDataProvider<DeviceVoltagePresets, PresetsList>
{
private:
    PresetsList data;

public:
    void persist(const DeviceVoltagePresets &device_voltage) override { data.updateVoltage(device_voltage); }
    void load() override {}
    void reset() override {}
    void remove(const DeviceVoltagePresets &device_voltage) override {}
    const PresetsList &get() const override { return data; }
};