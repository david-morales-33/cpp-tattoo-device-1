#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/interfaces/physical_device_activation.h>

class PhysicalActivationSelector
{
private:
    PhysicalDeviceActivation activation_list[3] = {
        PhysicalDeviceActivation::NO_PEDAL,
        PhysicalDeviceActivation::PULSES,
        PhysicalDeviceActivation::CONTINUOUS};

    Selector selector = Selector(3);

public:
    PhysicalDeviceActivation getActivation() const { return activation_list[selector.getSelector()]; }
    const int &getSelector() const { return selector.getSelector(); }

    void left() { selector.getSelector() == 0 ? selector.setSelector(2) : selector.decrement(); }
    void right() { selector.getSelector() == 2 ? selector.setSelector(0) : selector.increment(); }

    void setSelector(PhysicalDeviceActivation boot)
    {
        boot == PhysicalDeviceActivation::NO_PEDAL ? selector.setSelector(0) : //
            boot == PhysicalDeviceActivation::PULSES ? selector.setSelector(1)
                                                     : selector.setSelector(2);
    }
};