#pragma once
#include <vector>
#include <core/remote_devices/data_transfer_objects/device.h>

class DeviceList
{
private:
    Device lineDevice = Device(DeviceType::LINE);
    Device shadeDevice = Device(DeviceType::SHADE);
    Device pedalDevice = Device(DeviceType::PEDAL);

    Device &resolve(DeviceType type)
    {
        switch (type)
        {
        case DeviceType::LINE:
            return lineDevice;
        case DeviceType::SHADE:
            return shadeDevice;
        case DeviceType::PEDAL:
            return pedalDevice;
        }
        throw std::runtime_error("Invalid DeviceType");
    }

    const Device &resolve(DeviceType type) const
    {
        switch (type)
        {
        case DeviceType::LINE:
            return lineDevice;
        case DeviceType::SHADE:
            return shadeDevice;
        case DeviceType::PEDAL:
            return pedalDevice;
        }
        throw std::runtime_error("Invalid DeviceType");
    }

public:
    std::vector<Device> getConnectedDevices() const 
    {
        std::vector<Device> connected_devices;
        const Device *all[3] = {&lineDevice, &shadeDevice, &pedalDevice};

        for (auto dev : all)
            if (dev->getDeviceState() == DeviceState::CONNECTED)
                connected_devices.push_back(*dev);

        return connected_devices;
    }

    bool connectDevice(const Device &device)
    {
        Device &slot = resolve(device.getDeviceType());

        if (slot.getDeviceState() != DeviceState::DISCONNECTED)
            return false;

        slot.setMacAddressId(device.getMacAddressId());
        slot.setName(device.getName());
        slot.setDeviceState(DeviceState::CONNECTED);
        return true;
    }

    bool disconnectDevice(DeviceType type)
    {
        Device &slot = resolve(type);
        
        if (slot.getDeviceState() != DeviceState::CONNECTED)
            return false;

        slot = Device(type);
        return true;
    }

    const Device &getDevice(DeviceType type) const { return resolve(type); }
    Device &getDevice(DeviceType type) { return resolve(type); }
};