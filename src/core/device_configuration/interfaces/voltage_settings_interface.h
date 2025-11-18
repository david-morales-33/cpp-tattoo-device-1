#include <core/device_configuration/data_transfer_objects/voltage.h>

class VoltageSettingsInterface
{
    virtual void load() = 0;
    virtual void update(Voltage voltage) = 0;
    virtual void getLineDevices() const = 0;
    virtual void getShadeDevices() const = 0;
};