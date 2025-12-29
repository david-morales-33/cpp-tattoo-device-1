#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/performance/data_transfer_objects/performance.h>

class PerformanceTestProvider : public IDataProvider<Performance, Performance>
{
private:
    Performance performance;

public:
    void persist(const Performance &_performance) { performance = _performance; }
    void load()
    {
        performance.setStartTime("02:21:23");
        performance.setEndTime("03:28:00");
        performance.setTotalTime("01:07:00");
        performance.setDeviceTime("00:52:14");
    }
    const Performance &get() const { return performance; }
};