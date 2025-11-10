#pragma once
#include <infrastructure/input.h>
#include <infrastructure/display.h>
#include <application/link_devices/linked_devices_menu.h>

class LinkDevicesController
{
private:
    Display &display;
    DevicesListData devices;
    Input input;
    LinkedDevicesMenu linkedDevicesMenu;
    bool state = LOW;

public:
    explicit LinkDevicesController(Display &disp, DevicesListData dev) : display(disp), devices(dev), linkedDevicesMenu(disp, dev) {}

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

        if (input.isPressed(RIGHT))
        {
            linkedDevicesMenu.setDevSelector(0);
            linkedDevicesMenu.setSelectorSize(devices.available_devices.size());
            linkedDevicesMenu.right();
        }
        if (input.isPressed(LEFT))
        {
            linkedDevicesMenu.setDevSelector(0);
            linkedDevicesMenu.setSelectorSize(devices.linked_devices.size());
            linkedDevicesMenu.left();
        }
        linkedDevicesMenu.render();
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
};