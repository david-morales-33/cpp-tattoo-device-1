#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/device_configuration/data_transfer_objects/voltage.h>
#include <core/device_configuration/data_transfer_objects/voltage_list.h>

class DeviceConfigurationTestProvider : public IDataProvider<Voltage, VoltageList>
{
private:
    VoltageList data;

public:
    void persist(const Voltage &data) override {}
    void load() override {}
    void reset() override {}
    void remove(const Voltage &data) override {}
    const VoltageList &get() const override { return data; }
};