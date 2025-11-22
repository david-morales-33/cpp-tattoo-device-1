#pragma once
#include <core/remote_devices/interfaces/remote_devices_repository.h>
#include <infrastructure/persistence/remote_devices/remote_devices_eeprom_provider.h>

class RemoteDevicesEepromRepository : public IRemoteDevicesRepository
{
private:
    IDataProvider<Device, std::vector<Device>> &provider;

public:
    explicit RemoteDevicesEepromRepository(RemoteDevicesEepromProvider &_provider) : provider(_provider) {}

    void save(Device device) override { provider.persist(device); }
    void remove(Device device) override { provider.remove(device); }
    const std::vector<Device> &list() const override { return provider.get(); }
};