#pragma once
#include <array>
#include <vector>
#include <core/remote_devices/data_transfer_objects/remote_device.h>
#include <core/remote_devices/data_transfer_objects/remote_device.h>

class RemoteDeviceList
{
private:
    std::array<RemoteDevice, 3> devices = {
        RemoteDevice("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", LINE),
        RemoteDevice("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", SHADE),
        RemoteDevice("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", PEDAL)};

    bool isValid(DeviceType dev_type) { return devices[dev_type].getDeviceState() == DISCONNECTED; }

public:
    // const std::array<RemoteDevice, 3> &getDevices() const { return devices; }

    std::vector<RemoteDevice> getConnectedDevices() const
    {
        std::vector<RemoteDevice> connected_devices = {};
        for (int i = 0; i < devices.size(); i++)
        {
            if (devices[i].getDeviceState() == CONNECTED)
                connected_devices.push_back(devices[i]);
        }
        return connected_devices;
    }

    void connetDevice(RemoteDevice device)
    {
        if (isValid(device.getDeviceType()))
        {
            devices[device.getDeviceType()].setMacAddressId(device.getMacAddressId());
            devices[device.getDeviceType()].setName(device.getName());
            devices[device.getDeviceType()].setDeviceState(CONNECTED);
        }
    }
};