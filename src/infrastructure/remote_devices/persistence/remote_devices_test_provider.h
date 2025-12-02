#pragma once

#include <core/shared/interfaces/data_provider.h>
#include <core/remote_devices/data_transfer_objects/device.h>
#include <core/remote_devices/data_transfer_objects/device_list.h>
#include <vector>

class RemoteDevicesTestProvider : public IDataProvider<Device, std::vector<Device>>
{
private:
    DeviceList device_list;
    Device test_device1 = Device("Mach.86.AC", "AE:32:5C:EF:0A", DeviceType::PEDAL);
    Device test_device2 = Device("Mach.0F.AE", "AE:32:5C:EF:0A", DeviceType::LINE);
    Device test_device3 = Device("Mach.0C.AE", "AE:32:5C:EF:0A", DeviceType::SHADE);
    mutable std::vector<Device> connected_devices;

public:
    void persist(const Device &data) override
    {

        device_list.connectDevice(data);
    }
    void load() override
    {
        persist(test_device1);
        persist(test_device2);
        persist(test_device3);
    }
    void reset() override
    {
        remove(DeviceType::LINE);
        remove(DeviceType::SHADE);
        remove(DeviceType::PEDAL);
    }
    void remove(const Device &data) override { device_list.disconnectDevice(data.getDeviceType()); }
    const std::vector<Device> &get() const override
    {
        connected_devices = device_list.getConnectedDevices();
        return connected_devices;
    }
};
