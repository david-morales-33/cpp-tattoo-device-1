#pragma once
#include <core/remote_devices/interfaces/remote_devices_interface.h>
#include <core/remote_devices/interfaces/device_type.h>
#include <core/remote_devices/data_transfer_objects/remote_device.h>
#include <core/remote_devices/data_transfer_objects/remote_device_list.h>

class RemoteDevicesInMemoryRepository : public IRemoteDevicesInterface
{
private:
    RemoteDevice device_shade_linked = RemoteDevice{};
    RemoteDevice device_pedal_linked = RemoteDevice{};
    RemoteDevice device_line_linked = RemoteDevice{};
    RemoteDeviceList devices_list;  // data base (EEPROM simulate)

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
    void removeDevice(const char *mac_addresss_id) override
    {
        const RemoteDevice *device = devices_list.getDevice(mac_addresss_id);

        if (device != nullptr)
        {
            devices_list.removeDevice(mac_addresss_id);
            if (device->getDeviceType() == LINE)
                device_line_linked = RemoteDevice{};

            else if (device->getDeviceType() == SHADE)
                device_shade_linked = RemoteDevice{};

            else if (device->getDeviceType() == PEDAL)
                device_pedal_linked = RemoteDevice{};
        }
    }
    const RemoteDeviceList &search() const override { return devices_list; }
};