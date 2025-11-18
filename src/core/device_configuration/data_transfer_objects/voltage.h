#pragma once
#include <core/device_configuration/interfaces/voltage_type.h>
#include <core/device_configuration/interfaces/voltage_element.h>

class Voltage
{
private:
    VoltageElement element;
    VoltageType type;
    float value;

public:
    Voltage(VoltageElement _element, VoltageType _type, float _value) : element(_element), value(_value), type(_type) {}

    VoltageType getType() { return type; }
    VoltageElement getElement() { return element; }
    const float getValue() const { return value; }

    void setValue(float _value) { value = _value; }
};