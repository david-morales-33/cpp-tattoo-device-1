#pragma once
#include <core/performance/interfaces/timeType.h>
#include <core/shared/data_transfer_objects/_timer.h>

class PerformanceTime
{
private:
    TimeType type;
    const char *time;

public:
    PerformanceTime(
        TimeType _type) : type(_type) {}
    PerformanceTime(
        TimeType _type,
        const char *_time) : type(_type), time(_time) {}

    TimeType getType() const { return type; }
    const char *getTime() const { return time; }
    void setTime(const char *_time) { time = _time; }
};