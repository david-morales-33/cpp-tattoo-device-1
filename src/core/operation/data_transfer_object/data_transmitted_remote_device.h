#pragma once
#include <core/operation/data_transfer_object/payload.h>

class DataTransmittedRemoteDevice
{
private:
    const char *mac_address_id;
    Payload payload;

public:
    explicit DataTransmittedRemoteDevice(const char *_mac_address_id, Payload _payload) : mac_address_id(_mac_address_id), payload(_payload) {}
    void setMacAddressId(const char *_mac_address_id) { mac_address_id = _mac_address_id; }
    void setPayload(Payload _payload) { payload = _payload; }
    const char *getMacAddressId() { return mac_address_id; }
    const Payload &getPayload() const { return payload; }
};