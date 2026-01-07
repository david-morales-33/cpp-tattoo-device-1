#pragma once
#include <vector>
#include <core/presets/data_transfer_objects/remote_device_machine.h>

class ConnectedDevicesList
{
private:
    std::vector<RemoteDeviceMachine> remote_device_line;
    std::vector<RemoteDeviceMachine> remote_device_shade;

public:
    bool save(RemoteDeviceMachine remote_device)
    {
        if (remote_device.getDeviceType() == MachineType::LINE)
        {
            if (remote_device_line.size() != 0)
                return false;
            remote_device_line.push_back(remote_device);
            return true;
        }
        else
        {
            if (remote_device_shade.size() != 0)
                return false;
            remote_device_shade.push_back(remote_device);
            return true;
        }
    }

    bool remove(RemoteDeviceMachine remote_device)
    {
        if (remote_device.getDeviceType() == MachineType::LINE)
        {
            if (remote_device_line.size() == 0)
                return false;
            remote_device_line.clear();
            return true;
        }
        else
        {
            if (remote_device_shade.size() == 0)
                return false;
            remote_device_shade.clear();
            return true;
        }
    }

    const std::vector<RemoteDeviceMachine> &getLineDevice() const { return remote_device_line; }
    const std::vector<RemoteDeviceMachine> &getShadeDevice() const { return remote_device_shade; }
};