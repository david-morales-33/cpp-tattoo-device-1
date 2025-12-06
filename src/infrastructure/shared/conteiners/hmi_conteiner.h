#pragma once
#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>

class HMIContainer
{
private:
    InputImpl input_buttons;
    Display display;

public:
    bool begin()
    {
        input_buttons.begin();
        display.begin();
    }
    InputImpl &get_input() { return input_buttons; }
    Display &get_display() { return display; }
};
