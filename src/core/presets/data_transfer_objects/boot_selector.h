#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/interfaces/device_boot.h>
class BootSelector
{
private:
    DeviceBoot boot_list[4] = {
        DeviceBoot::CUSTOM_RAMP,
        DeviceBoot::INSTANT_POWER,
        DeviceBoot::LINEAR_RAMP,
        DeviceBoot::SOFT_START};

    Selector selector = Selector(4);

public:
    DeviceBoot getBoot() const { return boot_list[selector.getSelector()]; }
    const int &getSelector() const { return selector.getSelector(); }

    void left() { selector.getSelector() == 0 ? selector.setSelector(3) : selector.decrement(); }
    void right() { selector.getSelector() == 3 ? selector.setSelector(0) : selector.increment(); }

    void setSelector(DeviceBoot boot)
    {
        boot == DeviceBoot::CUSTOM_RAMP ? selector.setSelector(0) : boot == DeviceBoot::INSTANT_POWER ? selector.setSelector(1)
                                                                : boot == DeviceBoot::LINEAR_RAMP     ? selector.setSelector(2)
                                                                                                      : selector.setSelector(3);
    }
};