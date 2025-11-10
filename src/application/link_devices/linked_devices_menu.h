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
    int selector = 0;
    int selector_size = NULL;
    bool state = HIGH;

public:
    explicit LinkedDevicesMenu(Display &disp) : display(disp), view(disp) {}

    void render(DevicesListData devices)
    {
        if (selector_size == NULL)
            selector = devices.linked_devices.size();

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