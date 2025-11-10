#pragma once
#include <infrastructure/input.h>
#include <infrastructure/display.h>
#include <application/link_devices/linked_devices_menu.h>

class LinkDevicesController
{
private:
    Display &display;
    Input input;
    LinkedDevicesMenu linkedDevicesMenu;
    bool state = LOW;

public:
    explicit LinkDevicesController(Display &disp, DevicesListData dev) : display(disp), linkedDevicesMenu(disp, dev) {}

    void begin() { input.begin(); }

    void execute()
    {
        if (input.isPressed(UP))
            linkedDevicesMenu.up();
        if (input.isPressed(DOWN))
            linkedDevicesMenu.down();
        linkedDevicesMenu.render();
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
};