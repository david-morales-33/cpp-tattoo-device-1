#pragma once
#include <core/properties/interfaces/properties_timer_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/properties/data_transfer_object/timer_group.h>
#include <core/shared/data_transfer_objects/time.h>

class PropertiesTimerRepository : public IPropertiesTimerRepository
{
private:
    IDataProvider<Time, TimerGroup> &memory_provider;
    IDataProvider<Time, Time> &time_provider;

public:
    explicit PropertiesTimerRepository(
        IDataProvider<Time, TimerGroup> &_memory_provider,
        IDataProvider<Time, Time> &_time_provider) : memory_provider(_memory_provider), time_provider(_time_provider) {}
        
    void save(const Time &time) override { memory_provider.persist(time); }
    void setInitialTime() override
    {
        const char *time = time_provider.get().getFormat().c_str();
        Time start_time(time, TimeType::START_TIME);
        memory_provider.persist(start_time);
    }
    void setFinalTime() override
    {
        const char *time = time_provider.get().getFormat().c_str();
        Time end_time(time, TimeType::END_TIME);
        memory_provider.persist(end_time);
    }
    const TimerGroup &find() const { return memory_provider.get(); }
};
