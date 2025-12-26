#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/presets/data_transfer_objects/selectors.h>

class PresetsController
{
private:
    IInput &input;
    IMenuControllerVoid &devices_menu;
    IMenuControllerParams<int> &options_menu;

    IPopupController<PresetsSelectors> &modal_values;
    IPopupController<PresetsSelectors> &modal_voltage_selector;
    IPopupController<PresetsSelectors> &modal_boot_selector;
    IPopupController<PresetsSelectors> &modal_activation_selector;

    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;

public:
    explicit PresetsController(
        IInput &_input,
        IMenuControllerVoid &_devices_menu,
        IMenuControllerParams<int> &_options_menu,
        IPopupController<PresetsSelectors> &_modal_values,
        IPopupController<PresetsSelectors> &_modal_voltage_selector,
        IPopupController<PresetsSelectors> &_modal_boot_selector,
        IPopupController<PresetsSelectors> &_modal_activation_selector) : input(_input),
                                                                          devices_menu(_devices_menu),
                                                                          options_menu(_options_menu),
                                                                          modal_values(_modal_values),
                                                                          modal_voltage_selector(_modal_voltage_selector),
                                                                          modal_boot_selector(_modal_boot_selector),
                                                                          modal_activation_selector(_modal_activation_selector)
    {
    }
    void execute()
    {
        if (devices_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(BACK))
                resolveBack(0);
            if (input.isPressed(UP))
                devices_menu.previous();
            if (input.isPressed(DOWN))
                devices_menu.next();
            if (input.isPressed(ENTER) || input.isPressed(RIGHT))
                resolveEnter(0);
            devices_menu.render();
        }
        else if (options_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                options_menu.previous();
            if (input.isPressed(DOWN))
                options_menu.next();
            if (input.isPressed(BACK) || input.isPressed(LEFT))
                resolveBack(1);
            if (input.isPressed(ENTER))
                resolveEnter(1);
            options_menu.render();
        }
        else if (modal_values.getState() == InterfaceState::VISIBLE && options_menu.getSelector() == 0)
        {
            if (input.isPressed(UP))
                modal_values.up();
            if (input.isPressed(DOWN))
                modal_values.down();
            if (input.isPressed(BACK))
                resolveBack(2);
            if (input.isPressed(ENTER))
                resolveEnter(2);
            modal_values.render();
        }
        else if (modal_boot_selector.getState() == InterfaceState::VISIBLE && options_menu.getSelector() == 1)
        {
            if (input.isPressed(LEFT))
                modal_boot_selector.left();
            if (input.isPressed(RIGHT))
                modal_boot_selector.right();
            if (input.isPressed(BACK))
                resolveBack(2);
            if (input.isPressed(ENTER))
                resolveEnter(3);
            modal_boot_selector.render();
        }
        else if (modal_activation_selector.getState() == InterfaceState::VISIBLE && options_menu.getSelector() == 2)
        {
            if (input.isPressed(LEFT))
                modal_activation_selector.left();
            if (input.isPressed(RIGHT))
                modal_activation_selector.right();
            if (input.isPressed(BACK))
                resolveBack(2);
            if (input.isPressed(ENTER))
                resolveEnter(4);
            modal_activation_selector.render();
        }
        else if (modal_voltage_selector.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(LEFT))
                modal_voltage_selector.left();
            if (input.isPressed(RIGHT))
                modal_voltage_selector.right();
            if (input.isPressed(UP))
                modal_voltage_selector.up();
            if (input.isPressed(DOWN))
                modal_voltage_selector.down();
            if (input.isPressed(BACK))
                resolveBack(3);
            if (input.isPressed(ENTER))
                resolveEnter(5);
            modal_voltage_selector.render();
        }
    }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }
    InterfaceState getState() { return state; }

private:
    void resolveEnter(int option)
    {
        selectors.devices_selector = devices_menu.getSelector();
        selectors.options_selector = options_menu.getSelector();

        if (option == 0)
        {
            options_menu.load(devices_menu.getSelector());
            devices_menu.hide();
            options_menu.show();
        }
        else if (option == 1 && options_menu.getSelector() == 0)
        {
            modal_values.load(selectors);
            options_menu.hide();
            modal_values.show();
        }
        else if (option == 1 && options_menu.getSelector() == 1)
        {
            modal_boot_selector.load(selectors);
            options_menu.hide();
            modal_boot_selector.show();
        }
        else if (option == 1 && options_menu.getSelector() == 2)
        {
            modal_activation_selector.load(selectors);
            options_menu.hide();
            modal_activation_selector.show();
        }
        else if (option == 2)
        {
            selectors.voltage_selector = modal_values.getSelector();
            modal_voltage_selector.load(selectors);
            modal_values.hide();
            modal_voltage_selector.show();
        }
        else if (option == 3)
        {
            modal_boot_selector.enter();
            modal_boot_selector.hide();
            options_menu.show();
        }
        else if (option == 4)
        {
            modal_activation_selector.enter();
            modal_activation_selector.hide();
            options_menu.show();
        }
        else if (option == 5)
        {
            modal_voltage_selector.enter();
            modal_values.load(selectors);
            modal_voltage_selector.hide();
            modal_values.show();
        }
    }
    void resolveBack(int option)
    {
        if (option == 0)
        {
            hide();
        }
        else if (option == 1)
        {
            options_menu.hide();
            devices_menu.show();
        }
        else if (option == 2)
        {
            modal_values.hide();
            modal_activation_selector.hide();
            modal_boot_selector.hide();
            options_menu.show();
        }
        else if (option == 3)
        {
            modal_voltage_selector.hide();
            modal_values.show();
        }
    }
};
