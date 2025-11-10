#pragma once
#include <infrastructure/input.h>
#include <infrastructure/display.h>
#include <application/link_devices/linked_devices_menu.h>
#include <application/link_devices/linked_devices_window_menu.h>

class LinkDevicesController
{
private:
    Display &display;
    DevicesListData devices;
    Input input;
    LinkedDevicesMenu linkedDevicesMenu;
    LinkedDevicesWindowMenu windowMenu;

    bool state = LOW;

    void setLinkedDevices()
    {
        linkedDevicesMenu.setDevSelector(0);
        linkedDevicesMenu.setSelectorSize(devices.linked_devices.size());
        linkedDevicesMenu.left();
    }
    void setAvailableDevices()
    {
        linkedDevicesMenu.setDevSelector(0);
        linkedDevicesMenu.setSelectorSize(devices.available_devices.size());
        linkedDevicesMenu.right();
    }
    void setEnterLinkedDevices()
    {
        linkedDevicesMenu.hide();
        windowMenu.show();
    }
    void setBack()
    {
        linkedDevicesMenu.show();
        windowMenu.hide();
    }

public:
    explicit LinkDevicesController(Display &disp, DevicesListData dev) : display(disp), devices(dev), linkedDevicesMenu(disp, dev), windowMenu(disp, dev) {}

    void begin()
    {
        input.begin();
        linkedDevicesMenu.setSelectorSize(devices.linked_devices.size());
    }

    void execute()
    {
        if (input.isPressed(UP))
            linkedDevicesMenu.up();

        if (input.isPressed(DOWN))
            linkedDevicesMenu.down();

        if (input.isPressed(RIGHT) && devices.available_devices.size() != 0)
            setAvailableDevices();

        if (input.isPressed(LEFT) && devices.linked_devices.size() != 0)
            setLinkedDevices();

        if (input.isPressed(ENTER) && linkedDevicesMenu.getTypSelector() == 0)
            setEnterLinkedDevices();

        if (input.isPressed(BACK))
            setBack();

        if (linkedDevicesMenu.getState())
            linkedDevicesMenu.render();

        if (windowMenu.getState())
            windowMenu.render(linkedDevicesMenu.getDevSelector());
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
};