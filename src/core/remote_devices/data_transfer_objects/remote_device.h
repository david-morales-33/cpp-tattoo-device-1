#pragma once
#include <core/remote_devices/interfaces/device_type.h>
#include <core/remote_devices/interfaces/device_state.h>

class RemoteDevice
{
private:
    const char *name;
    const char *mac_address_id;
    DeviceType device_type;
    DeviceState device_state;

public:
    RemoteDevice(
        const char *_name,
        const char *_mac_address_id,
        DeviceType _device_type,
        DeviceState _device_state = DISCONNECTED) : name(_name),
                                                    mac_address_id(_mac_address_id),
                                                    device_type(_device_type),
                                                    device_state(_device_state) {};

    const char *getName() const { return name; };
    const char *getMacAddressId() const { return mac_address_id; }
    DeviceType getDeviceType() const { return device_type; }
    DeviceState getDeviceState() const { return device_state; }

    void setName(const char *_name) { name = _name; };
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
    void setDeviceType(DeviceType _device_type) { device_type = _device_type; }
    void setDeviceState(DeviceState _device_state) { device_state = _device_state; }
};