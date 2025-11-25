#pragma once

#include <infrastructure/shared/interfaces/input.h>
#include <core/shared/interfaces/menu_controller_void.h>

class MainMenuController
{
private:
    IInput &input;
    IMenuControllerVoid &menu;
    bool state = HIGH;

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
        if (state)
            menu.render();
    }

    void hide() { state = LOW; }
    void show() { state = HIGH; }
    bool menuState() { return state; }
    int getSelector() { return menu.getSelector(); }
};