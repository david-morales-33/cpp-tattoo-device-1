#pragma once

#include <core/main/data_transfer_objects/date.h>
#include <core/main/data_transfer_objects/time.h>

class DateTimeFormat
{
private:
    Date date;
    Time time;

public:
    explicit DateTimeFormat(Date _date, Time _time) : date(_date), time(_time) {}
    Time &getTime() { return time; }
    Date &getDate() { return date; }
    const Time &getTime() const { return time; }
    const Date &getDate() const { return date; }
};