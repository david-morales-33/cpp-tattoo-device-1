#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/performance/data_transfer_objects/performance_record.h>
#include <vector>

class RecordTestProvider : public IDataProvider<PerformanceRecord, std::vector<PerformanceRecord>>
{
private:
    std::vector<PerformanceRecord> performance_record_list = {
        PerformanceRecord{"29-12-2025-15:23", 252, 232},
        PerformanceRecord{"30-12-2025-16:14", 1200, 900},
        PerformanceRecord{"31-12-2025-12:14", 958, 745},
        PerformanceRecord{"01-01-2026-10:14", 1423, 1245},
        PerformanceRecord{"02-01-2026-10:14", 1423, 1045},
        PerformanceRecord{"02-02-2026-10:14", 1523, 945},
        PerformanceRecord{"03-10-2026-10:14", 1240, 545},
    };

public:
    void persist(const PerformanceRecord &record) { performance_record_list.push_back(record); }
    const std::vector<PerformanceRecord> &get() const { return performance_record_list; }
};