#pragma once
#include <vector>

struct DevicesData
{
    const char *mac_address_id;
    const char *name;
    bool linked_state;
};

struct DevicesListData
{
    std::vector<DevicesData> linked_devices = {};
    std::vector<DevicesData> enable_devices = {};
};

struct SelectorData
{
    int selector_x = 0;
    int selector_y = 0;
};