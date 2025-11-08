#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <application/shared/selector.h>

class ConfigureValuesMenu
{
private:
    Display &display;
    DeviceConfigurationView view;
    Selector selector;

public:
    explicit ConfigureValuesMenu(Display &disp, VoltageData volt) : display(disp), view(disp, volt), selector(4) {}
    void render()
    {
        display.firstPage();
        do
        {
            view.show(selector.getSelector());
        } while (display.nextPage());
    }
    void up() { selector.slideUp(); }
    void down() { selector.slideDown(); }
    int getSelector() { return selector.getSelector(); }
};