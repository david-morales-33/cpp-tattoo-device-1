#include <core/remote_devices/data_transfer_objects/remote_device.h>
#include <core/remote_devices/data_transfer_objects/remote_device_list.h>

class IRemoteDevicesInterface
{
public:
    virtual void save(RemoteDevice device) = 0;
    virtual void removeDevice(const char *mac_address_id) = 0;
    virtual const RemoteDeviceList &search() const = 0;
    virtual ~IRemoteDevicesInterface() {}
};