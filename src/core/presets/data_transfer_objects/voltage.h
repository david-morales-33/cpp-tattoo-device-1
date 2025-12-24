#pragma once
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/voltage_element.h>

class Voltage
{
private:
    VoltageElement element;
    float value = 0.0f;

public:
    Voltage(VoltageElement _element, float _value) : element(_element),
                                                     value(_value) {}

    VoltageElement getElement() const { return element; }
    const float getValue() const { return value; }

    void setValue(float _value) { value = _value; }
    void setElement(VoltageElement _element) { element = _element; }
};