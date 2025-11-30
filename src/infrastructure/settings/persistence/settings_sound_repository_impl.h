#pragma once
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/settings/data_transfer_objects/sound.h>

class SettingsSoundRepositoryImpl : public ISettingsSoundRepository
{
private:
    IDataProvider<Sound, Sound> &provider;

public:
    explicit SettingsSoundRepositoryImpl(IDataProvider<Sound, Sound> &_provider) : provider(_provider) {}

    void update(Sound sound) override { provider.persist(sound); }
    const Sound &get() const override { return provider.get(); }
};