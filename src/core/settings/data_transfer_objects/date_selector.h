#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <string>

class DateSelector
{
private:
    int day = 1;
    int month = 1;
    int year = 1;
    Selector selector = Selector(3, 2);

public:
    void setDate(int _day, int _month, int _year)
    {
        day = _day;
        month = _month;
        year = _year;
    }
    void increment()
    {
        switch (selector.getSelector())
        {
        case 1:
            if (day <= daysInMonth(month, year))
                day++;
            break;
        case 2:
            if (month <= 12)
                month++;
            break;
        default:
            year++;
            break;
        }
    }

    void decrement()
    {
        switch (selector.getSelector())
        {
        case 1:
            if (day > 1)
                day--;
            break;
        case 2:
            if (month > 1)
                month--;
            break;
        default:
            year--;
            break;
        }
    }

    std::string getDayFormated() const { return day < 10 ? "0" + std::to_string(day) : std::to_string(day); }
    std::string getMonthFormated() const { return month < 10 ? "0" + std::to_string(month) : std::to_string(month); }
    std::string getYearFormated() const { return std::to_string(year); }
    std::string getDateFormated() const { return getDayFormated() + "/" + getMonthFormated() + "/" + getYearFormated(); }

    int getSelector() const { return selector.getSelector(); }
    void left() { selector.decrement(); }
    void right() { selector.increment(); }

private:
    bool isLeap(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

    int daysInMonth(int m, int y) const
    {
        static const int days[12] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeap(y))
            return 29;

        return days[m - 1];
    }

    bool isValid(int d, int m, int y) const
    {
        if (m < 1 || m > 12)
            return false;
        if (d < 1 || d > daysInMonth(m, y))
            return false;
    }
};