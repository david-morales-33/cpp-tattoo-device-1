#pragma once
#include <core/operation/interfaces/remote_device_action.h>

class DataReceivedRemoteDevice
{
private:
    const char *mac_address_id;
    RemoteDeviceAction action;

public:
    explicit DataReceivedRemoteDevice(const char *_mac_address_id, RemoteDeviceAction _action) : mac_address_id(_mac_address_id), action(_action) {}
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
    void setAction(RemoteDeviceAction _action) { action = _action; }
    const char *getMacAddressId() { return mac_address_id; }
    const RemoteDeviceAction &getPayload() const { return action; }
};