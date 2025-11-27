#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/device_configuration/data_transfer_objects/voltage.h>
#include <core/device_configuration/data_transfer_objects/voltage_list.h>

class DeviceConfigurationTestProvider : public IDataProvider<Voltage, VoltageList>
{
private:
    VoltageList data;

public:
    void persist(const Voltage &_data) override
    {
        if (_data.getType() == VoltageType::LINE)
            data.getLine().updateByIndex(static_cast<int>(_data.getElement()), _data.getValue());
        else
            data.getShade().updateByIndex(static_cast<int>(_data.getElement()), _data.getValue());
    }
    void load() override {}
    void reset() override {}
    void remove(const Voltage &data) override {}
    const VoltageList &get() const override { return data; }
};