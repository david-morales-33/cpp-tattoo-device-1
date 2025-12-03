#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/properties/data_transfer_object/timer_group.h>
#include <core/shared/data_transfer_objects/time.h>

class PropertiesMemoryProvider : public IDataProvider<Time, TimerGroup>
{
private:
    TimerGroup time_list;

public:
    void persist(const Time &time) override { time_list.update(time); }
    void load() override {}
    void reset() override
    {
        time_list.update(Time("00:00:00", TimeType::START_TIME));
        time_list.update(Time("00:00:00", TimeType::END_TIME));
        time_list.update(Time("00:00:00", TimeType::TOTAL_TIME));
        time_list.update(Time("00:00:00", TimeType::DEVICE_TIME));
    }
    void remove(const Time &time) override { time_list.update(Time("00:00:00", time.getType())); }
    const TimerGroup &get() const override { return time_list; }
};