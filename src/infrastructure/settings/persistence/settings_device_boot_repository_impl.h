#pragma once
#include <core/settings/interfaces/settings_device_boot_repository.h>
#include <core/shared/interfaces/data_provider.h>

class SettingsBootRepositoryImpl : public ISettingsDeviceBootRepository
{
private:
    IDataProvider<DeviceBoot, DeviceBoot> &provider;

public:
    explicit SettingsBootRepositoryImpl(IDataProvider<DeviceBoot, DeviceBoot> &_provider) : provider(_provider) {}
    void update(DeviceBoot state) override { provider.persist(state); }
    DeviceBoot get() override { return provider.get(); }
};