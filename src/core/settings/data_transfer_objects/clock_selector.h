#pragma once
#include <core/main/interfaces/time_period.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <string>

class ClockSelector
{
private:
    int hour = 0;
    int minutes = 0;
    TimePeriod period = TimePeriod::AM;
    Selector selector = Selector(3);

public:
    void setTime(int _hour, int _minutes, TimePeriod _period)
    {
        hour = _hour;
        minutes = _minutes;
        period = _period;
    }

    const std::string getHoursFormated() const { return hour < 10 ? "0" + std::to_string(hour) : std::to_string(hour); }
    std::string getMinutesFormated() const { return minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes); }
    std::string getPeriodFormated() const { return period == TimePeriod::AM ? "a.m." : "p.m."; }

    int getHours() { return hour; }
    int getMinutes() { return minutes; }
    TimePeriod getPeriod() { return period; }
    const int &getSelector() const { return selector.getSelector(); }

    std::string getTimeFormated() { return (getHoursFormated() + ":" + getMinutesFormated() + " " + getPeriodFormated()); }

    void increment()
    {
        switch (selector.getSelector())
        {
        case 0:
            hourIncrementer();
            break;
        case 1:
            if (minutes < 59)
                minutes++;
            else
            {
                minutes = 0;
                hourIncrementer();
            }
            break;
        default:
            switchPeriod();
            break;
        }
    }

    void decrement()
    {
        switch (selector.getSelector())
        {
        case 0:
            hourDecrementer();
            break;
        case 1:
            if (minutes > 0)
                minutes--;
            else
            {
                minutes = 59;
                hourDecrementer();
            }
            break;

        default:
            switchPeriod();
            break;
        }
    }

    void left() { selector.decrement(); }
    void right() { selector.increment(); }

private:
    void switchPeriod() { period = period == TimePeriod::AM ? TimePeriod::PM : TimePeriod::AM; }

    void hourIncrementer() { hour < 12 ? hour++ : hour = 1; }
    void hourDecrementer() { hour > 1 ? hour-- : hour = 12; }
};