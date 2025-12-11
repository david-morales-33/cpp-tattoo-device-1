#pragma once
#include <core/settings/interfaces/sound_state.h>
#include <core/settings/interfaces/physical_device_activation.h>
#include <core/settings/interfaces/remote_device_activation.h>
#include <core/settings/interfaces/device_boot.h>

class ISettingsSoundRepository
{
public:
    virtual void update(SoundState soud) = 0;
    virtual SoundState get() = 0;
    virtual ~ISettingsSoundRepository() {}
};