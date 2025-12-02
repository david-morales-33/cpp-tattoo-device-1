#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/interfaces/view_controller.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/data_transfer_objects/selector.h>

class PropertiesController
{
private:
    IInput &input;
    IMenuControllerVoid &menu;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit PropertiesController(
        IInput &_input,
        IMenuControllerVoid &_menu) : input(_input), menu(_menu) {}
    void execute()
    {
        if (input.isPressed(UP))
            menu.previous();
        if (input.isPressed(DOWN))
            menu.next();
        menu.render();
    }

    void hide() { state = InterfaceState::HIDDEN; }
    void show() { state = InterfaceState::VISIBLE; }
    InterfaceState getState() { return state; }
};