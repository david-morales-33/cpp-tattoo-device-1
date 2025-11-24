#pragma once
#include <core/main/data_transfer_objects/date_time_format.h>

class IMainDateTimeRepository
{
public:
    virtual void update(DateTimeFormat date) = 0;
    virtual const DateTimeFormat &get() const = 0;

    virtual void remove() = 0;

    virtual ~IMainDateTimeRepository() {}
};