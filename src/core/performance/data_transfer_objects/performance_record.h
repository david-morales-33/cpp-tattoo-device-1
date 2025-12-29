#pragma once

class PerformanceRecord
{
private:
    const char *date;
    int total_time = 0;
    int device_time = 0;

public:
    PerformanceRecord() {}
    PerformanceRecord(const char *_date, int _total_time, int _device_time) : date(_date), total_time(_total_time), device_time(_device_time) {}
    float getPerformance() { return ((device_time / total_time) * 100); }

    const char *getDate() { return date; }
    int getTotalTime() { return total_time; }
    int getDeviceTime() { return device_time; }
};