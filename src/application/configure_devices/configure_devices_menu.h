#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <application/shared/selector.h>

class ConfigureDevicesMenu
{
private:
    Display &display;
    DeviceConfigurationView view;
    Selector selector;
    bool state = HIGH;

public:
    explicit ConfigureDevicesMenu(Display &disp, VoltageData volt) : display(disp), view(disp, volt), selector(2) {}

    void render()
    {
        display.firstPage();
        do
        {
            view.show(selector.getSelector());
        } while (display.nextPage());
    }
    void up() { selector.decrement(); }
    void down() { selector.increment(); }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
    bool getState() { return state; }
    int getSelector() { return selector.getSelector(); }
};