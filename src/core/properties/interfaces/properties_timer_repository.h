#pragma once
#include <core/properties/interfaces/time_type.h>
#include <core/shared/data_transfer_objects/time.h>

class IPropertiesTimerRepository
{
public:
    virtual void save(int minutes) = 0;
    virtual void setInitialTime() = 0;
    virtual void setFinalTime() = 0;
    virtual const Time &find(TimeType type) const = 0;
    virtual ~IPropertiesTimerRepository() {}
};