#pragma once
#include <core/main/interfaces/time_period.h>
#include <string>

class TimeFormat
{
private:
    std::string time;
    TimePeriod prd;
    const char *hour;
    const char *minute;

public:
    TimeFormat(std::string _time) : time(_time) {}
    TimeFormat(const char *_hour,
               const char *_minutes,
               TimePeriod _prd) : hour(_hour), minute(_minutes), prd(_prd)
    {
        time = std::string(hour) + ":" + std::string(_minutes) + (_prd == TimePeriod::AM ? "AM" : "PP");
    }

    TimeFormat() : time() {}
    
    TimePeriod getPeriod() { return prd; }
    const char *getHour() { return hour; }
    const char *getMinute() { return minute; }
    std::string getTime() const { return time; }
};