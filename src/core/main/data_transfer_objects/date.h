#pragma once
#include <string>

class Date
{
private:
    const char *day;
    const char *month;
    const char *year;

public:
    explicit Date(const char *_day, const char *_month, const char *_year) : day(_day), month(_month), year(_year) {}
    const char *getDay() const { return day; }
    const char *getMonth() const { return month; }
    const char *getYear() const { return year; }
    const std::string getDate() const { return std::string(day) + "/" + std::string(month) + "/" + std::string(year); }
};