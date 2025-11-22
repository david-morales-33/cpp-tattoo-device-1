#pragma once
#include <core/settings/data_transfer_objects/date.h>
#include <core/settings/data_transfer_objects/hour.h>
#include <core/settings/data_transfer_objects/sound.h>

class SettingsRepository
{
    virtual void setHour(Hour hour) = 0;
    virtual void setDate(Date date) = 0;
    virtual void setSound(Sound soud) = 0;
    virtual const Sound &getSound() const = 0;
    virtual const Hour &getHour() const = 0;
    virtual const Date &getDate() const = 0;
};