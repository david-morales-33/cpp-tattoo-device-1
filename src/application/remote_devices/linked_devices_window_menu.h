#pragma once
#include <infrastructure/display.h>
#include <core/remote_devices/views/linked_devices_window.h>
#include <persistence/linked_devices/data.h>

class LinkedDevicesWindowMenu
{
private:
    Display &display;
    LinkedDevicesWindow window;
    DevicesListData devices;

    bool state = LOW;

public:
    explicit LinkedDevicesWindowMenu(Display &disp, DevicesListData dev) : display(disp), window(disp, dev), devices(dev) {}
    void render(int dev_selector = 0)
    {
        display.firstPage();
        do
        {
            window.show(dev_selector);
        } while (display.nextPage());
    }

    void show() { state = HIGH; }
    void hide() { state = LOW; }

    bool getState() { return state; }
};