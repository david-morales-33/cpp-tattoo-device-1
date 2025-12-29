#pragma once
#include <string>

class Timer
{
private:
    int secs = 0;

    int hours() const { return secs / 3600; }
    int minutes() const { return (secs % 3600) / 60; }
    int seconds() const { return secs % 60; }

public:
    Timer(int _secs)
        : secs(_secs) {}

    const std::string getFormat() const
    {
        std::string h = hours() < 10 ? "0" + std::to_string(hours()) : std::to_string(hours());
        std::string m = minutes() < 10 ? "0" + std::to_string(minutes()) : std::to_string(minutes());
        std::string s = seconds() < 10 ? "0" + std::to_string(seconds()) : std::to_string(seconds());
        return h + m + s;
    }

    Timer sum(Timer _time) const { return Timer(secs + _time.secs); }

    Timer subt(Timer _time) const
    {
        int result = secs - _time.secs;
        if (result < 0)
            result = 0;
        return Timer(result);
    }
};