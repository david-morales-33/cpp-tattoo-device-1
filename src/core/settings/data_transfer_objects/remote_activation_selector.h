#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/interfaces/remote_device_activation.h>

class RemoteActivationSelector
{
private:
    RemoteDeviceActivation activation_list[2] = {
        RemoteDeviceActivation::NO_PEDAL,
        RemoteDeviceActivation::PULSES};

    Selector selector = Selector(3);

public:
    RemoteDeviceActivation getActivation() const { return activation_list[selector.getSelector()]; }
    int getSelector() const { return selector.getSelector(); }

    void switchActivation() { selector.getSelector() == 0 ? selector.setSelector(1) : selector.setSelector(0); }
    void setSelector(RemoteDeviceActivation boot)
    {
        boot == RemoteDeviceActivation::NO_PEDAL ? selector.setSelector(0) : //
            selector.setSelector(1);
    }
};