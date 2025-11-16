#pragma once
#include <core/remote_devices/interfaces/remote_devices_interface.h>
#include <core/remote_devices/interfaces/device_type.h>
#include <core/remote_devices/data_transfer_objects/remote_device.h>
#include <core/remote_devices/data_transfer_objects/remote_device_list.h>

class RemoteDevicesInMemoryRepository : public IRemoteDevicesInterface
{
private:
    RemoteDevice device_shade_linked;
    RemoteDevice device_pedal_linked;
    RemoteDevice device_line_linked;
    RemoteDeviceList devices_list;

public:
    void save(RemoteDevice device) override
    {
        if (device.getDeviceType() == LINE && devices_list.isDeviceValid(device.getMacAddressId()))
        {
            device_line_linked = device;
            devices_list.addDevice(device);
        }
        else if (device.getDeviceType() == SHADE && devices_list.isDeviceValid(device.getMacAddressId()))
        {
            device_shade_linked = device;
            devices_list.addDevice(device);
        }
        else if (device.getDeviceType() == PEDAL && devices_list.isDeviceValid(device.getMacAddressId()))
        {
            device_pedal_linked = device;
            devices_list.addDevice(device);
        }
    }
    void removeDevice(const char *id) override {}
    RemoteDeviceList search() override { return devices_list; }
};