#pragma once
#include <vector>
#include <core/remote_devices/data_transfer_objects/device.h>

class DeviceList
{
private:
    Device lineDevice = Device("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", LINE);
    Device shadeDevice = Device("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", SHADE);
    Device pedalDevice = Device("XXX.XXX.XXX", "XX:XX:XX:XX:XX:XX", PEDAL);

    Device &resolve(DeviceType type)
    {
        switch (type)
        {
        case LINE:
            return lineDevice;
        case SHADE:
            return shadeDevice;
        case PEDAL:
            return pedalDevice;
        }
    }

    const Device &resolve(DeviceType type) const
    {
        switch (type)
        {
        case LINE:
            return lineDevice;
        case SHADE:
            return shadeDevice;
        case PEDAL:
            return pedalDevice;
        }
    }

public:
    std::vector<Device> getConnectedDevices() const
    {
        std::vector<Device> connected_devices;
        const Device *all[3] = {&lineDevice, &shadeDevice, &pedalDevice};

        for (auto dev : all)
            if (dev->getDeviceState() == CONNECTED)
                connected_devices.push_back(*dev);

        return connected_devices;
    }

    bool connectDevice(const Device &device)
    {
        Device &slot = resolve(device.getDeviceType());

        if (slot.getDeviceState() != DISCONNECTED)
            return false;

        slot.setMacAddressId(device.getMacAddressId());
        slot.setName(device.getName());
        slot.setDeviceState(CONNECTED);
        return true;
    }

    void disconnectDevice(DeviceType type) { resolve(type).setDeviceState(DISCONNECTED); }

    const Device &getDevice(DeviceType type) const { return resolve(type); }
};