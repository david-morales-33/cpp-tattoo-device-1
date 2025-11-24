#pragma once
#include <string>

class Time
{
private:
    const char *hour;
    const char *minute;

public:
    explicit Time(const char *_hour,
                  const char *_minute) : hour(_hour), minute(_minute) {}

    const char *getHour() { return hour; }
    const char *getMinute() { return minute; }
    std::string getTime() { return std::string(hour) + ":" + std::string(minute); }
};