#pragma once
#include <core/shared/interfaces/menu_controller_params.h>
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/sound_state.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>

class SettingsController
{
private:
    IInput &input;
    IMenuControllerParams<int> &menu;

    IPopupController<SettingsSelectors> &sound_modal;
    IPopupController<SettingsSelectors> &clock_modal;
    IPopupController<SettingsSelectors> &date_modal;
    IPopupController<SettingsSelectors> &reset_modal;

    IPopupController<SettingsSelectors> &pedal_dev_f_modal;
    IPopupController<SettingsSelectors> &pedal_dev_r_modal;
    IPopupController<SettingsSelectors> &device_boot_modal;

    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit SettingsController(
        IInput &_input,
        IMenuControllerParams<int> &_menu,
        IPopupController<SettingsSelectors> &_sound_modal,
        IPopupController<SettingsSelectors> &_reset_modal,
        IPopupController<SettingsSelectors> &_clock_modal,
        IPopupController<SettingsSelectors> &_date_modal,
        IPopupController<SettingsSelectors> &_pedal_dev_f_modal,
        IPopupController<SettingsSelectors> &_pedal_dev_r_modal,
        IPopupController<SettingsSelectors> &_device_boot_modal) : input(_input),
                                                                   menu(_menu),
                                                                   sound_modal(_sound_modal),
                                                                   reset_modal(_reset_modal),
                                                                   clock_modal(_clock_modal),
                                                                   date_modal(_date_modal),
                                                                   pedal_dev_f_modal(_pedal_dev_f_modal),
                                                                   pedal_dev_r_modal(_pedal_dev_r_modal),
                                                                   device_boot_modal(_device_boot_modal),
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
        else if (device_boot_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 2 && selector.getSelector() == 1)
        {
            device_boot_modal.render();
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
        else if (side_selector == 1 && value_selector == 2)
            device_boot_modal.show();
    }
};