#pragma once
#include <core/shared/data_transfer_objects/selector.h>

class VoltageSelector
{
private:
    int selector = 0;
    float value = 0.0f;

public:
    void setUnit() { selector = 0; }
    void setDecimal() { selector = 1; }
    void setValue(float _value) { value = _value; }

    void increment()
    {
        int uni = int(value);
        float dec = value - uni;
        if (selector == 0)
        {
            if (value <= 11)
            {
                uni = uni + 1;
                value = (uni + dec);
            }
        }
        else
        {
            if (value < 12)
            {
                dec = dec + 0.1;
                value = (uni + dec);
            }
        }
    }
    void decrement()
    {
        int uni = int(value);
        float dec = value - uni;

        if (selector == 0)
        {
            if (value > 2)
            {
                uni = uni - 1;
                value = (uni + dec);
            }
        }
        else
        {
            if (value > 2)
            {
                dec = dec - 0.1;
                value = (uni + dec);
            }
        }
    }

    float getValue() const { return value; }
    const int &getSelector() const { return selector; }
};