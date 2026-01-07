#pragma once

class RemoteDevice
{
private:
    const char *name;
    const char *mac_address_id;

public:
    RemoteDevice(
        const char *_name,
        const char *_mac_address_id) : name(_name),
                                    mac_address_id(_mac_address_id) {};

    const char *getName() const { return name; };
    const char *getMacAddressId() const { return mac_address_id; }

    void setName(const char *_name) { name = _name; };
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
};