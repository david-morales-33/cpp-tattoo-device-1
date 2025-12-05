#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/settings/interfaces/sound_state.h>

class SettingsSoundTestProvider : public IDataProvider<SoundState, SoundState>
{
private:
    SoundState state = SoundState::ON;

public:
    void persist(const SoundState &data) override { state = data; }
    void load() override {}
    void reset() override { state = SoundState::ON; }
    void remove(const SoundState &data) override {}
    const SoundState &get() const override { return state; }
};