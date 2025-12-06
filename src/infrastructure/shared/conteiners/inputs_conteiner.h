#pragma once
#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>

class InputsContainer
{
private:
    InputImpl input_buttons;

public:
    void begin() { input_buttons.begin(); }
    InputImpl &get_input_buttons() { return input_buttons; }
};
