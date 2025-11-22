#pragma once
#include <core/settings/data_transfer_objects/sound.h>

class ISettingsSoundRepository
{
public:
    virtual void update(Sound soud) = 0;
    virtual const Sound &get() const = 0;

    virtual ~ISettingsSoundRepository() {}
};