#pragma once
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/shared/interfaces/data_provider.h>

class SettingsSoundRepositoryImpl : public ISettingsSoundRepository
{
private:
    IDataProvider<SoundState, SoundState> &provider;

public:
    explicit SettingsSoundRepositoryImpl(IDataProvider<SoundState, SoundState> &_provider) : provider(_provider) {}
    void update(SoundState state) override { provider.persist(state); }
    SoundState get() override { return provider.get(); }
};