#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/presets.h>
#include <core/presets/data_transfer_objects/presets_list.h>
#include <core/presets/data_transfer_objects/voltage.h>

class PresetsTestProvider : public IDataProvider<Presets, PresetsList>
{
private:
    PresetsList data;

public:
    void persist(const Presets &presets){}
    void load() {}
    void reset() {}
    void remove(const Presets &Presets) {}
    const PresetsList &get() const { return data; }
};