#pragma once
#include <core/presets/interfaces/presets_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/presets/data_transfer_objects/presets_list.h>

class PresetsRepositoryImpl : public IPresetsRepository
{
private:
    IDataProvider<Voltage, PresetsList> &provider;

public:
    void update(Voltage voltage) { provider.persist(voltage); }
    const PresetsList &getPresets() { provider.get(); }
};