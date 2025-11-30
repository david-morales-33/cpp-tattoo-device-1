#pragma once
#include <core/remote_devices/interfaces/remote_devices_repository.h>
#include <core/shared/interfaces/data_provider.h>

class RemoteDevicesRepositoryTestImpl : public IRemoteDevicesRepository
{
private:
    IDataProvider<Device, std::vector<Device>> &provider;
    std::vector<Device> disconnected_devices;

public:
    explicit RemoteDevicesRepositoryTestImpl(IDataProvider<Device, std::vector<Device>> &_provider) : provider(_provider) {}

    void save(Device device) override { provider.persist(device); }
    void remove(Device device) override { provider.remove(device); }
    void search()
    {
        disconnected_devices = {
            Device{"dev.30.AE", "30:AE:A4:07:0D:64", DeviceType::LINE, DeviceState::DISCONNECTED}, 
            Device{"dev.32.AC", "32:AC:A4:07:0D:64", DeviceType::SHADE, DeviceState::DISCONNECTED}
        };
    }
    const std::vector<Device> &findConnetedDevices() { return provider.get(); }
    const std::vector<Device> &findDisconnectedDevices() { return disconnected_devices; }
};