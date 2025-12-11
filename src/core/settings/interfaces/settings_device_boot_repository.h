#pragma once

#include <core/settings/interfaces/device_boot.h>

class ISettingsDeviceBootRepository
{
public:

    virtual void update(DeviceBoot boot) = 0;
    virtual DeviceBoot get() = 0;

    virtual ~ISettingsDeviceBootRepository() {}
};