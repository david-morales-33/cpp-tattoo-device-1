#pragma once
#include <core/settings/data_transfer_objects/date.h>
#include <core/settings/data_transfer_objects/hour.h>

class ISettingsDateRepository
{
    virtual void updateHour(Hour hour) = 0;
    virtual void updateDate(Date date) = 0;
    virtual const Hour &getHour() const = 0;
    virtual const Date &getDate() const = 0;

    virtual void remove() = 0;

    virtual ~ISettingsDateRepository() {}
};