#pragma once

enum class DeviceBoot
{
    SOFT_START = 0,
    LINEAR_RAMP = 1,
    INSTANT_POWER = 2,
    CUSTOM_RAMP = 3
};