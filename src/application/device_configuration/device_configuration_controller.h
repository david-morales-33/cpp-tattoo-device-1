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
    IMenuControllerVoid &devices_menu;
    IMenuControllerParams<int> &values_menu;
    IPopupController<ConfigurationSelectors> &modal;

    InterfaceState state = InterfaceState::HIDDEN;
    ConfigurationSelectors selectors;

    void setEnterDevices()
    {
        values_menu.load(devices_menu.getSelector());
        devices_menu.hide();
        values_menu.show();
    }
    void setEnterModal()
    {
        selectors.devices_selector = devices_menu.getSelector();
        selectors.values_selector = values_menu.getSelector();
        modal.load(selectors);
        modal.show();
        values_menu.hide();
    }
    void setBackValues()
    {
        devices_menu.show();
        values_menu.hide();
    }
    void setEnterData()
    {
        modal.enter();
        modal.hide();
        values_menu.load(devices_menu.getSelector());
        values_menu.show();
    }
    void setBackModal()
    {
        modal.hide();
        values_menu.show();
    }

public:
    explicit ConfigureDevicesController(
        IInput &_input,
        IMenuControllerVoid &_devices_menu,
        IMenuControllerParams<int> &_values_menu,
        IPopupController<ConfigurationSelectors> &_modal) : input(_input), devices_menu(_devices_menu), values_menu(_values_menu), modal(_modal) {}

    void execute()
    {
        if (devices_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(BACK))
                hide();
            if (input.isPressed(UP))
                devices_menu.previous();
            if (input.isPressed(DOWN))
                devices_menu.next();
            if (input.isPressed(ENTER) || input.isPressed(RIGHT))
                setEnterDevices();
            devices_menu.render();
        }
        else if (values_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                values_menu.previous();
            if (input.isPressed(DOWN))
                values_menu.next();
            if (input.isPressed(ENTER))
                setEnterModal();
            if (input.isPressed(BACK) || input.isPressed(LEFT))
                setBackValues();
            values_menu.render();
        }
        else if (modal.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(LEFT))
                modal.left();
            if (input.isPressed(RIGHT))
                modal.right();
            if (input.isPressed(UP))
                modal.up();
            if (input.isPressed(DOWN))
                modal.down();
            if (input.isPressed(BACK))
                setBackModal();
            if (input.isPressed(ENTER))
                setEnterData();
            modal.render();
        }
    }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }
    InterfaceState getState() { return state; }
};