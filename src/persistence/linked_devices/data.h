#pragma once
#include <vector>

struct DevicesData
{
    const char *mac_address_id;
    const char *name;
    DevicesData(const char *_mac_address_id, const char *_name) : mac_address_id(_mac_address_id), name(_name) {}
};

struct DevicesListData
{
    std::vector<DevicesData> linked_devices = {};
    std::vector<DevicesData> available_devices = {};
    DevicesListData(std::vector<DevicesData> _linked_devices, std::vector<DevicesData> _available_devices) : linked_devices(_linked_devices), available_devices(_available_devices) {}
};

struct SelectorData
{
    int selector_x = 0;
    int selector_y = 0;
};