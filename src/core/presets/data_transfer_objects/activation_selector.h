#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/presets/interfaces/device_activation.h>

class ActivationSelector
{
private:
    DeviceActivation activation_list[3] = {
        DeviceActivation::NO_PEDAL,
        DeviceActivation::PULSES,
        DeviceActivation::CONTINUOUS};

    Selector selector = Selector(3);

public:
    DeviceActivation getActivation() const { return activation_list[selector.getSelector()]; }
    const int &getSelector() const { return selector.getSelector(); }

    void left() { selector.getSelector() == 0 ? selector.setSelector(2) : selector.decrement(); }
    void right() { selector.getSelector() == 2 ? selector.setSelector(0) : selector.increment(); }

    void setSelector(DeviceActivation boot)
    {
        boot == DeviceActivation::NO_PEDAL ? selector.setSelector(0) : //
            boot == DeviceActivation::PULSES ? selector.setSelector(1)
                                             : selector.setSelector(2);
    }
};