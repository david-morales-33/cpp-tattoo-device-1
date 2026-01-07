#pragma once
#include <core/shared/interfaces/machine_type.h>

class RemoteDeviceMachine
{
private:
    const char *name;
    const char *mac_address_id;
    MachineType device_type;

public:
    RemoteDeviceMachine(
        const char *_name,
        const char *_mac_address_id,
        MachineType _device_type) : name(_name),
                                    mac_address_id(_mac_address_id),
                                    device_type(_device_type) {};

    const char *getName() const { return name; };
    const char *getMacAddressId() const { return mac_address_id; }
    MachineType getDeviceType() const { return device_type; }

    void setName(const char *_name) { name = _name; };
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
    void setDeviceType(MachineType _device_type) { device_type = _device_type; }
};