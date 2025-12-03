#pragma once
#include <string>
#include <core/properties/interfaces/time_type.h>

class Time
{
private:
    const char *time;
    TimeType type;
    int secs = 0;

    int hours() const { return secs / 3600; }
    int minutes() const { return (secs % 3600) / 60; }
    int seconds() const { return secs % 60; }

public:
    Time(int _secs)
        : secs(_secs), type(TimeType::NONE) {}

    Time(const char *_time, TimeType _type)
        : time(_time), secs(0), type(_type) {}

    const char *getTime() const { return time; }
    const TimeType getType() const { return type; }
    void setTime(const char *_time) { time = _time; }

    const std::string getFormat() const
    {
        std::string h = hours() < 10 ? "0" + std::to_string(hours()) : std::to_string(hours());
        std::string m = minutes() < 10 ? "0" + std::to_string(minutes()) : std::to_string(minutes());
        std::string s = seconds() < 10 ? "0" + std::to_string(seconds()) : std::to_string(seconds());
        return h + m + s;
    }

    Time sum(Time _time) const { return Time(secs + _time.secs); }

    Time subt(Time _time) const
    {
        int result = secs - _time.secs;
        if (result < 0)
            result = 0;
        return Time(result);
    }
};