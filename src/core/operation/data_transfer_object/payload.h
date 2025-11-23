#pragma once
#include <core/operation/interfaces/remote_device_action.h>

struct Payload
{
    RemoteDeviceAction action;
    float value;
};
