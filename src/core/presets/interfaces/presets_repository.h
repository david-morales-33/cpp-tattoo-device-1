#pragma once
#include <core/presets/data_transfer_objects/voltage.h>
#include <core/presets/data_transfer_objects/presets_list.h>

class IPresetsRepository
{
public:
    virtual void update(Voltage voltage) = 0;
    virtual const PresetsList &getPresets() const = 0;
    virtual ~IPresetsRepository() = default;
};