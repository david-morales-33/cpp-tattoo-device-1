#pragma once
#include <core/shared/data_transfer_objects/time.h>
#include <array>

class TimerGroup
{
private:
    std::array<Time, 4> time_list;

public:
    TimerGroup() : time_list{
                       Time{TimeType::START_TIME},
                       Time{TimeType::END_TIME},
                       Time{TimeType::TOTAL_TIME},
                       Time{TimeType::DEVICE_TIME}} {}

    const Time &resolve(TimeType type) const
    {
        for (auto &_time : time_list)
        {
            if (_time.getType() == type)
                return _time;
        }
    }

    void update(const Time &time)
    {
        for (auto &_time : time_list)
        {
            if (_time.getType() == time.getType())
                _time.setTime(time.getTime());
        }
    }
};
