#pragma once
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/voltage_element.h>

class DeviceVoltagePresets
{
private:
    MachineType type;
    VoltageElement element;
    float value = 0.0f;

public:
    DeviceVoltagePresets(MachineType _type,
                      VoltageElement _element,
                      float _value) : type(_type), element(_element), value(_value) {}

    MachineType getType() const { return type; }
    VoltageElement getElement() const { return element; }
    const float &getValue() const { return value; }
};