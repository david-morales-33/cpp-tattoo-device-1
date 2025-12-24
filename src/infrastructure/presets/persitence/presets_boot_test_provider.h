#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/presets/data_transfer_objects/voltage.h>

class PresetsBootTestProvider : public IDataProvider<DeviceBootPresets, PresetsList>
{
private:
    PresetsList data;

public:
    void persist(const DeviceBootPresets &presets) override {}
    void load() override {}
    void reset() override {}
    void remove(const DeviceBootPresets &Presets) override {}
    const PresetsList &get() const override { return data; }
};