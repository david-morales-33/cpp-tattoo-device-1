#pragma once

struct DevicesData
{
    const char *name;
    const char *address_mac;
    bool linked_state;
};

struct SelectorData
{
    int selector_x = 0;
    int selector_y = 0;
};