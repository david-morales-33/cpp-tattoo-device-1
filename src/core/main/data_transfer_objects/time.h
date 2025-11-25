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

    const char *getHour() const { return hour; }
    const char *getMinute() const { return minute; }
    const std::string getTime() const { return std::string(hour) + ":" + std::string(minute); }
};