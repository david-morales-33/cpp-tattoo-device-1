#pragma once
#include <core/remote_devices/data_transfer_objects/device.h>
#include <core/remote_devices/data_transfer_objects/device_list.h>

class IRemoteDevicesRepository
{
public:
    virtual void save(Device device) = 0;
    virtual void remove(Device device) = 0;
    virtual const std::vector<Device> &list() const = 0;
    virtual ~IRemoteDevicesRepository() {}
};