#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/interfaces/view_controller.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/remote_devices/data_transfer_objects/device.h>

class RemoteDevicesController
{
private:
    IInput &input;
    IMenuControllerParams<int> &menu_devices;
    IPopupController<Device> &modal_connected_devices;
    IPopupController<Device> &modal_disconnected_devices;
    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;

    void left()
    {
        selector.decrement();
        menu_devices.load(selector.getSelector());
    }
    void right()
    {
        selector.increment();
        menu_devices.load(selector.getSelector());
    }

public:
    explicit RemoteDevicesController(
        IInput &_input,
        IMenuControllerParams<int> &_menu_devices,
        IPopupController<Device> &_modal_connected_devices,
        IPopupController<Device> &_modal_disconnected_devices) : input(_input),
                                                               menu_devices(_menu_devices),
                                                               modal_connected_devices(_modal_connected_devices),
                                                               modal_disconnected_devices(_modal_disconnected_devices),
                                                               selector(2) {}
    void execute()
    {

        if (menu_devices.getState() == InterfaceState::VISIBLE)
        { // => devices menu
            if (input.isPressed(UP))
                menu_devices.previous();
            if (input.isPressed(DOWN))
                menu_devices.next();
            if (input.isPressed(LEFT))
                left();
            if (input.isPressed(RIGHT))
                right();

            menu_devices.render();
        }

        else if (modal_connected_devices.getState() == InterfaceState::VISIBLE)
        { // => connected devices modal
            modal_connected_devices.render();
        }

        else if (modal_disconnected_devices.getState() == InterfaceState::VISIBLE)
        { // => disconnected devices modal
            modal_disconnected_devices.render();
        }
    }

    void hide() { state = InterfaceState::HIDDEN; }
    void show() { state = InterfaceState::VISIBLE; }
    InterfaceState getState() { return state; }
};