#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/shared/data_transfer_objects/time.h>

class PropertiesTimerTestProvider : public IDataProvider<Time, Time>
{
private:
    Time time_test{"05:08:21", TimeType::NONE};

public:
    void persist(const Time &data) override {}
    void load() override {}
    void reset() override {}
    void remove(const Time &data) override {}
    const Time &get() const override { return time_test; }
};