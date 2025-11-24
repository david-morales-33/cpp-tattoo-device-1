#pragma once

#include <core/main/data_transfer_objects/date.h>
#include <core/main/data_transfer_objects/time.h>

class DateTimeFormat
{
private:
    Date date;
    Time time;

public:
    Time &getTime() { return time; }
    Date &getDate() { return date; }
    const Time &getTime() const { return time; }
    const Date &getDate() const { return date; }
};