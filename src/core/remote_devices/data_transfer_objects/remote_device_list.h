#pragma once
#include <vector>
#include <core/remote_devices/data_transfer_objects/remote_device.h>

class RemoteDeviceList
{
private:
    std::vector<RemoteDevice> devices = {};

public:
    const std::vector<RemoteDevice> &getDevices() const { return devices; }

    void addDevice(RemoteDevice device)
    {
        if (isDeviceValid(device.getMacAddressId()))
            devices.push_back(device);
    }

    void removeDevice(const char *mac_address_id)
    {
        for (int i = 0; i < devices.size(); i++)
            if (devices[i].getMacAddressId() == mac_address_id)
                devices.erase(devices.begin() + i);
    }

    bool isDeviceValid(const char *mac_addres_id) const
    {
        for (const auto &d : devices)
            if (d.getMacAddressId() == mac_addres_id)
                return false;
        return true;
    }
};