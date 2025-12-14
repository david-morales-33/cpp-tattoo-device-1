#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/settings/interfaces/device_boot.h>

class SettingsDeviceBootTestProvider : public IDataProvider<DeviceBoot, DeviceBoot>
{
private:
    DeviceBoot boot = DeviceBoot::INSTANT_POWER;

public:
    void persist(const DeviceBoot &data) override { boot = data; }
    void load() override {}
    void reset() override { boot = DeviceBoot::INSTANT_POWER; }
    void remove(const DeviceBoot &data) override {}
    const DeviceBoot &get() const override { return boot; }
};