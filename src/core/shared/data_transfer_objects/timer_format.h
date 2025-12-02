#pragma once
#include <string>

class TimerFormat
{
private:
    int secs = 0;

public:
    explicit TimerFormat(int _secs = 0) : secs(_secs) {}

    int hours() const { return secs / 3600; }
    int minutes() const { return (secs % 3600) / 60; }
    int seconds() const { return secs % 60; }

    const std::string getTimerFormat() const
    {
        std::string h = hours() < 10 ? "0" + std::to_string(hours()) : std::to_string(hours());
        std::string m = minutes() < 10 ? "0" + std::to_string(minutes()) : std::to_string(minutes());
        std::string s = seconds() < 10 ? "0" + std::to_string(seconds()) : std::to_string(seconds());
        return h + m + s;
    }

    TimerFormat sum(TimerFormat _timerFormat) const
    {
        return TimerFormat(secs + _timerFormat.secs);
    }
    
    TimerFormat subt(TimerFormat _timerFormat) const
    {
        int result = secs - _timerFormat.secs;
        if (result < 0)
            result = 0;
        return TimerFormat(result);
    }
};