#pragma once

#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/interfaces/interface_state.h>

class MainMenuController
{
private:
    IInput &input;
    IMenuControllerVoid &menu;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit MainMenuController(IInput &_input, IMenuControllerVoid &_menu) : input(_input), menu(_menu) {}

    void execute()
    {
        if (input.isPressed(LEFT))
            menu.previous();
        if (input.isPressed(RIGHT))
            menu.next();
        if (input.isPressed(ENTER))
            hide();
        if (state == InterfaceState::VISIBLE)
            menu.render();
    }

    void hide() { state = InterfaceState::HIDDEN; }
    void show() { state = InterfaceState::VISIBLE; }
    InterfaceState getState() { return state; }
    int getSelector() { return menu.getSelector(); }
};