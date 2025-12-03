#pragma once
#include <core/shared/data_transfer_objects/time.h>
#include <array>

class TimerGroup
{
private:
    std::array<Time, 4> time_list;

public:
    TimerGroup() : time_list{
                       Time{"00:00:00", TimeType::START_TIME},
                       Time{"00:00:00", TimeType::END_TIME},
                       Time{"00:00:00", TimeType::TOTAL_TIME},
                       Time{"00:00:00", TimeType::DEVICE_TIME}} {}

    const Time &resolve(TimeType type) const
    {
        for (auto &_time : time_list)
        {
            if (_time.getType() == type)
                return _time;
        }
        throw std::runtime_error("TimeType not found in TimerGroup");
    }

    void update(const Time &time)
    {
        for (auto &_time : time_list)
        {
            if (_time.getType() == time.getType())
                _time.setTime(time.getTime());
        }
        throw std::runtime_error("TimeType not found in TimerGroup");
    }
};
