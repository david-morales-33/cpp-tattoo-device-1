#pragma once
#include <string>
#include <core/properties/interfaces/time_type.h>

class Time
{
private:
    const char *time;
    TimeType type;

public:
    explicit Time(const char *_time, TimeType _type) : time(_time), type(_type) {}
    explicit Time(TimeType _type) : type(_type) {}
    explicit Time() {}

    const char *getTime() const { return time; }
    const TimeType getType() const { return type; }
    void setTime(const char *_time) { time = _time; }
};