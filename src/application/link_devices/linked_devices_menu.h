#pragma once
#include <infrastructure/display.h>
#include <core/linked_devices/views/linked_devices_view.h>
#include <persistence/linked_devices/data.h>

class LinkedDevicesMenu
{
private:
    Display &display;
    LinkedDevicesView view;
    DevicesListData devices;

    int dev_selector = 0;
    int typ_selector = 0;
    int element_size = 0;

    bool state = HIGH;

public:
    explicit LinkedDevicesMenu(Display &disp, DevicesListData dev) : display(disp), view(disp, dev), devices(dev) {}

    void render()
    {
        display.firstPage();
        do
        {
            view.show(typ_selector, dev_selector);
        } while (display.nextPage());
    }

    void up()
    {
        if (dev_selector > 0)
            dev_selector = dev_selector - 1;
    }

    void down()
    {
        if (dev_selector < (element_size - 1))
            dev_selector = dev_selector + 1;
    }

    void left() { typ_selector = 0; }
    void right() { typ_selector = 1; }
    void show() { state = HIGH; }
    void hide() { state = LOW; }

    bool getState() { return state; }
    int getDevSelector() { return dev_selector; }
    int getTypSelector() { return typ_selector; }

    void setSelectorSize(int _element_size) { element_size = _element_size; }
    void setDevSelector(int _dev_selector = 0) { dev_selector = _dev_selector; }
};