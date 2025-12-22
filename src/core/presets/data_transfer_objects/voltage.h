#pragma once
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/voltage_element.h>

class Voltage
{
private:
    VoltageElement element;
    MachineType type;
    float value = 0.0f;

public:
    Voltage(VoltageElement _element, MachineType _type, float _value) : element(_element),
                                                                        value(_value),
                                                                        type(_type) {}

    MachineType getType() const { return type; }

    VoltageElement getElement() const { return element; }

    const float getValue() const { return value; }

    void setValue(float _value) { value = _value; }
    void setElement(VoltageElement _element) { element = _element; }
    void setType(MachineType _type) { type = _type; }
};