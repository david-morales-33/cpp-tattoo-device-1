#pragma once

#include <core/main/data_transfer_objects/date_format.h>
#include <core/main/data_transfer_objects/time_format.h>

class DateTimeFormat
{
private:
    DateFormat date;
    TimeFormat time;

public:
    DateTimeFormat(DateFormat _date, TimeFormat _time) : date(_date), time(_time) {}
    DateTimeFormat() {}
    TimeFormat &getTime() { return time; }
    DateFormat &getDate() { return date; }
    const TimeFormat &getTime() const { return time; }
    const DateFormat &getDate() const { return date; }
};