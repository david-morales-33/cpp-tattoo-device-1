#pragma once

class PerformanceRecord
{
private:
    const char *date;
    float total_time = 0.0f;
    float device_time = 0.0f;
    float performance = 0.0f;

public:
    PerformanceRecord() {}
    PerformanceRecord(const char *_date, float _total_time, float _device_time) : date(_date), total_time(_total_time), device_time(_device_time), performance((_device_time / _total_time) * 100) {}
    const float getPerformance() const { return performance; }

    const char *getDate() { return date; }
    const float getTotalTime() const { return total_time; }
    const float getDeviceTime() const { return device_time; }
};