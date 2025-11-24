#pragma once

class IInput
{
public:
    virtual bool isPressed(int pin) = 0;
    virtual ~IInput() {}
};