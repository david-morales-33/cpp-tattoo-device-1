#pragma once
#include <core/device_configuration/data_transfer_objects/voltage_group.h>

class VoltageList
{
private:
    VoltageGroup line{LINE};
    VoltageGroup shade{SHADE};

public:
    VoltageGroup &getLine() { return line; }
    VoltageGroup &getShade() { return shade; }
    const VoltageGroup &getLine() const { return line; }
    const VoltageGroup &getShade() const { return shade; }
};