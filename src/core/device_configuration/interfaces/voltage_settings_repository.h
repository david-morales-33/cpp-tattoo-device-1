#pragma once
#include <core/device_configuration/data_transfer_objects/voltage.h>
#include <core/device_configuration/data_transfer_objects/voltage_group.h>

class IVoltageSettingsRepository
{
public:
    virtual void update(Voltage voltage) = 0;
    virtual const VoltageGroup &getLineDevices() const = 0;
    virtual const VoltageGroup &getShadeDevices() const = 0;
    virtual ~IVoltageSettingsRepository() = default;
};