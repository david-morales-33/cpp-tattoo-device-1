#pragma once
#include <infrastructure/presets/persitence/presets_remote_device_test_listener.h>

class ListenerContainerTest
{
private:
    PresetsRemoteDeviceTestListener remote_devices_listener;

public:
    void begin()
    {
        remote_devices_listener.begin();
    }
    PresetsRemoteDeviceTestListener &get_remote_devices_listener() { return remote_devices_listener; }
};
