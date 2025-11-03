#pragma once
#include <Arduino.h>

class Timer
{
private:
    unsigned long startTime = 0;
    unsigned long duration;
    bool active = false;

public:
    Timer(unsigned long ms) : duration(ms) {}

    void start()
    {
        startTime = millis();
        active = true;
    }

    void stop()
    {
        active = false;
    }

    bool isFinished()
    {
        if (!active)
            return false;
        if (millis() - startTime >= duration)
        {
            active = false;
            return true;
        }
        return false;
    }

    bool isActive() const
    {
        return active;
    }
};