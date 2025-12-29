#pragma once
#include <core/performance/interfaces/performance_respository.h>
#include <core/shared/interfaces/data_provider.h>
#include <vector>

class PerformanceRepositoryImpl : public IPerformanceRepository
{
private:
    IDataProvider<Performance, Performance> &performance_provider;
    IDataProvider<PerformanceRecord, std::vector<PerformanceRecord>> &record_list_provider;

public:
    explicit PerformanceRepositoryImpl(IDataProvider<Performance, Performance> &_performance_provider,
                                       IDataProvider<PerformanceRecord, std::vector<PerformanceRecord>> &_record_list_provider) : performance_provider(_performance_provider),
                                                                                                                                  record_list_provider(_record_list_provider) {}
    void save(Performance performance) { performance_provider.get(); }
    const Performance &find() const { return performance_provider.get(); }
    const std::vector<PerformanceRecord> &searchRecords() const { return record_list_provider.get(); }
};