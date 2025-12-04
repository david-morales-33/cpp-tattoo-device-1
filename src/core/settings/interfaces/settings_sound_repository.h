#pragma once
#include <core/settings/interfaces/sound_state.h>

class ISettingsSoundRepository
{
public:
    virtual void update(SoundState soud) = 0;
    virtual SoundState get() = 0;

    virtual ~ISettingsSoundRepository() {}
};