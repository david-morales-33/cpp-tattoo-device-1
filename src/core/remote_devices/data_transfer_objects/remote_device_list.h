#pragma once
#include <vector>
#include <algorithm>
#include <cstring>
#include <core/remote_devices/data_transfer_objects/remote_device.h>

class RemoteDeviceList
{
private:
    std::vector<RemoteDevice> devices = {};

public:
    const std::vector<RemoteDevice> &getDevices() const { return devices; }

    void addDevice(RemoteDevice device) { devices.push_back(device); }

    void removeDevice(const char *mac_address_id)
    {
        devices.erase(
            std::remove_if(
                devices.begin(),
                devices.end(),
                [mac_address_id](const RemoteDevice &it)
                { return it.getMacAddressId() == mac_address_id; }),
            devices.end());
    }

    const RemoteDevice *getDevice(const char *mac_address_id) const
    {
        for (const auto &dev : devices)
            if (strcmp(dev.getMacAddressId(), mac_address_id) == 0)
                return &dev;
        return nullptr;
    }

    bool isDeviceValid(const char *mac_addres_id) const
    {
        bool flag = false;
        for (const auto &d : devices)
            if (d.getMacAddressId() == mac_addres_id)
                flag = true;
        return flag;
    }
};