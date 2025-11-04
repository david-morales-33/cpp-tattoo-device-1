#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <persistence/device_configuration/data.h>

class DeviceConfigurationSelector : public DeviceConfigurationView
{
private:
    Display &display;
    VoltageData data;

public:
    explicit DeviceConfigurationSelector(Display &disp, VoltageData volt) : DeviceConfigurationView(disp, volt), display(disp), data(volt) {}

    void show(int dev_selector = 0, int val_selector = 0)
    {
        DeviceConfigurationView::show(dev_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawFrame(65, ((16 * val_selector) + 1), 62, 14, 1); // selector 2//ini=2-->16++
    }
};