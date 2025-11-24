#pragma once
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/main/data_transfer_objects/date_time_format.h>

class MainDateTimeRepositoryImpl : public IMainDateTimeRepository
{
private:
    IDataProvider<DateTimeFormat, DateTimeFormat> &provider;

public:
    explicit MainDateTimeRepositoryImpl(IDataProvider<DateTimeFormat, DateTimeFormat> &_provider) : provider(_provider) {}

    void update(DateTimeFormat date_time) override { provider.persist(date_time); }
    const DateTimeFormat &get() const override { return provider.get(); }
    void remove() override { provider.reset(); }
};