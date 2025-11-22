#pragma once
#include <core/settings/data_transfer_objects/date_time_format.h>

class ISettingsDateTimeRepository
{
public:
    virtual void update(DateTimeFormat date) = 0;
    virtual const DateTimeFormat &get() const = 0;

    virtual void remove() = 0;

    virtual ~ISettingsDateTimeRepository() {}
};