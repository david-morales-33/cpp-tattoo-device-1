#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_selector.h>
#include <application/shared/selector.h>

class ConfigureValuesMenu
{
private:
    Display &display;
    DeviceConfigurationSelector view;
    Selector val_selector;
    bool state = LOW;

public:
    explicit ConfigureValuesMenu(Display &disp, VoltageData volt) : display(disp), view(disp, volt), val_selector(4) {}
    void render(int dev_selector = 0)
    {
        display.firstPage();
        do
        {
            view.show(dev_selector, val_selector.getSelector());
        } while (display.nextPage());
    }
    void up() { val_selector.decrement(); }
    void down() { val_selector.increment(); }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
    bool getState() { return state; }
    int getSelector() { return val_selector.getSelector(); }
};