#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/main/data_transfer_objects/date_time_format.h>

class MainDateTimeProviderTest : public IDataProvider<DateTimeFormat, DateTimeFormat>
{
private:
    DateTimeFormat date_time = DateTimeFormat(DateFormat("24", "11", "2025"), TimeFormat("05", "15", TimePeriod::PM));

public:
    void persist(const DateTimeFormat &data) override {}
    const DateTimeFormat &get() const override { return date_time; }

    void load() override {}  // ← FALTABA
    void reset() override {} // ← FALTABA
    void remove(const DateTimeFormat &) override {}
};