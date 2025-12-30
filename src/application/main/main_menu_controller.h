#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <application/shared/controller.h>

class MainMenuController : public IController
{
private:
    IInput &input;
    IMenuControllerVoid &menu;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit MainMenuController(IInput &_input, IMenuControllerVoid &_menu) : input(_input), menu(_menu) {}

    void execute() override
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

    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int getSelector() const { return menu.getSelector(); }
};