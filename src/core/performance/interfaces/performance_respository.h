#pragma once
#include <core/performance/data_transfer_objects/performance.h>
#include <vector>

class PerformanceRepository
{
    virtual void save(Performance performance) = 0;
    virtual const Performance &find() const = 0;
    virtual const std::vector<PerformanceRecord> &searchRecords() const = 0;
};