#pragma once
#include <infrastructure/display.h>
#include <core/linked_devices/views/available_devices_window.h>
#include <persistence/linked_devices/data.h>

class AvailableDevicesWindowMenu
{
private:
    Display &display;
    AvailableDevicesWindow window;
    DevicesListData devices_listed;
    LinkedDevicesData devices_linked;

    int selector = 0;

    bool state = LOW;

public:
    explicit AvailableDevicesWindowMenu(Display &disp, DevicesListData dev_list, LinkedDevicesData dev_link) : display(disp), window(disp, dev_list, dev_link), devices_linked(dev_link), devices_listed(dev_list) {}

    void render()
    {
        display.firstPage();
        do
        {
            window.show();
        } while (display.nextPage());
    }

    void slide() { selector == 0 ? selector = 1 : selector = 0; }
    void hide() { state = LOW; }
    void show() { state = HIGH; }
    bool getState() { return state; }
};