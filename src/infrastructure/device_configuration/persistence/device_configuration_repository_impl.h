#pragma once
#include <core/device_configuration/interfaces/device_configuration_repository.h>
#include <core/shared/interfaces/data_provider.h>
#include <core/device_configuration/data_transfer_objects/voltage_group.h>
#include <core/device_configuration/data_transfer_objects/voltage_list.h>

class DeviceConfigurationRepositoryImpl : public IDeviceConfigurationRepository
{
private:
    IDataProvider<Voltage, VoltageList> &provider;

public:
    explicit DeviceConfigurationRepositoryImpl(IDataProvider<Voltage, VoltageList> &_provider) : provider(_provider) {}

    void update(Voltage voltage) override { provider.persist(voltage); }
    const VoltageGroup &getLineDevices() const override { return provider.get().getLine(); }
    const VoltageGroup &getShadeDevices() const override { return provider.get().getShade(); }
};