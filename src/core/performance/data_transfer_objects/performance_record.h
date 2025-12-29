#pragma once

class PerformanceRecord
{
private:
    int day = 0;
    int hour = 0;
    int total_time = 0;
    int device_time = 0;

public:
    PerformanceRecord() {}
    PerformanceRecord(int _total_time, int _device_time, int _day, int _hour) : day(_day), hour(_hour), total_time(_total_time), device_time(_device_time) {}
    float getPerformance() { return ((device_time / total_time) * 100); }
    int getDay() const { return day; }
    int getHour() const { return hour; }
    int getTotalTime() { return total_time; }
    int getDeviceTime() { return device_time; }
};