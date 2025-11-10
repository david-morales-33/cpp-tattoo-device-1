#pragma once
#include <infrastructure/display.h>
#include <core/linked_devices/views/linked_devices_view.h>
#include <application/shared/selector.h>
#include <persistence/linked_devices/data.h>

class LinkedDevicesMenu
{
private:
    Display &display;
    LinkedDevicesView view;
    DevicesListData devices;
    int selector = 0;
    int selector_size = 0;
    bool state = HIGH;

public:
    explicit LinkedDevicesMenu(Display &disp, DevicesListData dev) : display(disp), view(disp), devices(dev) {}

    void render()
    {
        selector_size = devices.linked_devices.size();

        display.firstPage();
        do
        {
            view.show(devices, 0, selector);
        } while (display.nextPage());
    }

    void up()
    {
        if (selector > 0)
            selector = selector - 1;
    }
    void down()
    {
        if (selector < (selector_size - 1))
            selector = selector + 1;
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
    bool getState() { return state; }
    int getSelector() { return selector; }
};