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

    PerformanceRecord getRecord() { return record; }
    PerformanceTime &getStartTime() { return start_time; }
    PerformanceTime &getEndTime() { return end_time; }
    PerformanceTime &getTotalTime() { return total_time; }
    PerformanceTime &getDeviceTime() { return device_time; }
};