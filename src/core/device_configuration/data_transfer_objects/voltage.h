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
    Voltage(VoltageElement _element, VoltageType _type, float _value) : element(_element),
                                                                        value(_value),
                                                                        type(_type) {}
    Voltage() : element(VoltageElement::NONE),
                type(VoltageType::NONE),
                value(0.0f) {}

    VoltageType getType() const { return type; }

    VoltageElement getElement() const { return element; }

    const float getValue() const { return value; }

    void setValue(float _value) { value = _value; }
    void setElement(VoltageElement _element) { element = _element; }
    void setType(VoltageType _type) { type = _type; }
};