#pragma once
#include <core/performance/data_transfer_objects/performance_record.h>
#include <core/performance/data_transfer_objects/performance_time.h>

class Performance
{
private:
    PerformanceRecord record;
    PerformanceTime start_time{TimeType::START};
    PerformanceTime end_time{TimeType::END};
    PerformanceTime total_time{TimeType::TOTAL};
    PerformanceTime device_time{TimeType::DEVICE};

public:
    Performance() {}
    Performance(
        PerformanceRecord _record,
        PerformanceTime _start_time,
        PerformanceTime _end_time,
        PerformanceTime _total_time,
        PerformanceTime _device_time) : record(_record),
                                        start_time(_start_time),
                                        end_time(_end_time),
                                        total_time(_total_time),
                                        device_time(_device_time) {}

    void setRecord(PerformanceRecord _record) { record = _record; }
    void setStartTime(const char *time) { start_time.setTime(time); }
    void setEndTime(const char *time) { end_time.setTime(time); }
    void setTotalTime(const char *time) { total_time.setTime(time); }
    void setDeviceTime(const char *time) { device_time.setTime(time); }

    const PerformanceRecord getRecord() const { return record; }
    const PerformanceTime &getStartTime() const { return start_time; }
    const PerformanceTime &getEndTime() const { return end_time; }
    const PerformanceTime &getTotalTime() const { return total_time; }
    const PerformanceTime &getDeviceTime() const { return device_time; }
};