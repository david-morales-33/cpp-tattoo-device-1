#pragma once
#include <core/remote_devices/interfaces/device_type.h>

class RemoteDevice
{
private:
    const char *name;
    const char *mac_address_id;
    DeviceType device_type;

public:
    RemoteDevice() : mac_address_id("xxx.xxx.xxx"), name("xxx:xxx:xxx:xxx"), device_type(DeviceType::NONE) {} // ← estado "vacío"
    RemoteDevice(const char *_name, const char *_mac_address_id, DeviceType _device_type) : name(_name), mac_address_id(_mac_address_id), device_type(_device_type) {};

    const char *getName() const { return name; };
    const char *getMacAddressId() const { return mac_address_id; }
    DeviceType getDeviceType() const { return device_type; }

    void setName(const char *_name) { name = _name; };
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
    void setDeviceType(DeviceType _device_type) { device_type = _device_type; }
    bool isValid() const { return device_type != DeviceType::NONE; }
};