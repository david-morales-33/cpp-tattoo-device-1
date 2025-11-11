#pragma once
#include <vector>

struct DevicesData
{
    const char *mac_address_id;
    const char *device_type;
    const char *name;
    DevicesData(const char *_mac_address_id, const char *_device_type, const char *_name ) : mac_address_id(_mac_address_id), device_type(_device_type), name(_name) {}
};

struct DevicesListData
{
    std::vector<DevicesData> linked_devices = {};
    std::vector<DevicesData> available_devices = {};
    DevicesListData(std::vector<DevicesData> _linked_devices, std::vector<DevicesData> _available_devices) : linked_devices(_linked_devices), available_devices(_available_devices) {}
};

struct LinkedDevicesData
{
    std::vector<DevicesData> line_device = {};
    std::vector<DevicesData> shade_device = {};
    LinkedDevicesData(std::vector<DevicesData> _line_device, std::vector<DevicesData> _shade_device) : line_device(_line_device), shade_device(_shade_device) {}
};