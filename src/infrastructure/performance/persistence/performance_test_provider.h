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
        performance.getStartTime().setTime("02:21:23");
        performance.getEndTime().setTime("03:28:00");
        performance.getTotalTime().setTime("01:07:00");
        performance.getDeviceTime().setTime("00:52:14");
    }
    const Performance &get() const { return performance; }
};