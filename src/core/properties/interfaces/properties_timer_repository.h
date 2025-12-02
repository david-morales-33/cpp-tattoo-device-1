#pragma once
#include <core/properties/interfaces/time_type.h>
#include <core/properties/data_transfer_object/timer_group.h>

class IPropertiesTimerRepository
{
public:
    virtual void save(int minutes) = 0;
    virtual void setInitialTime() = 0;
    virtual void setFinalTime() = 0;
    virtual const TimerGroup &find() const = 0;
    virtual ~IPropertiesTimerRepository() {}
};