#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/device_configuration/data_transfer_objects/selectors.h>

class ConfigureDevicesController
{
private:
    IInput &input;
    IMenuControllerParams<int> &menu;
    IPopupController<void> &sound_modal;
    IPopupController<void> &reset_modal;
    IPopupController<void> &clock_modal;
    IPopupController<void> &date_modal;
    IPopupController<void> &pedal_dev_f_modal;
    IPopupController<void> &pedal_dev_r_modal;
    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit ConfigureDevicesController(
        IInput &_input,
        IMenuControllerParams<int> &_menu,
        IPopupController<void> &_sound_modal,
        IPopupController<void> &_reset_modal,
        IPopupController<void> &_clock_modal,
        IPopupController<void> &_date_modal,
        IPopupController<void> &_pedal_dev_f_modal,
        IPopupController<void> &_pedal_dev_r_modal,
        Selector selector) : input(_input),
                             menu(_menu),
                             sound_modal(_sound_modal),
                             reset_modal(_reset_modal),
                             clock_modal(_clock_modal),
                             date_modal(_date_modal),
                             pedal_dev_f_modal(_pedal_dev_f_modal),
                             pedal_dev_r_modal(_pedal_dev_r_modal),
                             selector(2) {}

    void execute()
    {
        if (menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                menu.previous();
            if (input.isPressed(DOWN))
                menu.next();
            if (input.isPressed(LEFT))
                left();
            if (input.isPressed(RIGHT))
                right();
            if (input.isPressed(ENTER))
                enterResolve(selector.getSelector(), menu.getSelector());
            menu.render();
        }
        else if (sound_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 0 && selector.getSelector() == 0)
        {
            sound_modal.render();
        }
        else if (clock_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 1 && selector.getSelector() == 0)
        {
            clock_modal.render();
        }
        else if (date_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 2 && selector.getSelector() == 0)
        {
            date_modal.render();
        }
        else if (reset_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 3 && selector.getSelector() == 0)
        {
            reset_modal.render();
        }
        else if (pedal_dev_f_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 0 && selector.getSelector() == 1)
        {
            pedal_dev_f_modal.render();
        }
        else if (pedal_dev_r_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 1 && selector.getSelector() == 1)
        {
            pedal_dev_r_modal.render();
        }
    }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }
    InterfaceState getState() { return state; }

private:
    void right()
    {
        selector.increment();
        menu.load(selector.getSelector());
    }
    void left()
    {
        selector.decrement();
        menu.load(selector.getSelector());
    }
    void enterResolve(int side_selector, int value_selector)
    {
        menu.hide();
        if (side_selector == 0 && value_selector == 0)
            sound_modal.show();
        else if (side_selector == 0 && value_selector == 1)
            clock_modal.show();
        else if (side_selector == 0 && value_selector == 2)
            date_modal.show();
        else if (side_selector == 0 && value_selector == 3)
            reset_modal.show();
        else if (side_selector == 1 && value_selector == 0)
            pedal_dev_f_modal.show();
        else if (side_selector == 1 && value_selector == 1)
            pedal_dev_r_modal.show();
    }
};