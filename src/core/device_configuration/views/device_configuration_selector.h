#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_view.h>

class DeviceConfigurationSelector : public DeviceConfigurationView
{
private:
    Display &display;

public:
    explicit DeviceConfigurationSelector(Display &disp) : DeviceConfigurationView(disp), display(disp) {}

    void show(const VoltageGroup &data, int val_selector = 0)
    {
        DeviceConfigurationView::show(data);
        display.setFontMode(1);
        display.setColor(0);
        display.drawFrame(65, ((16 * val_selector) + 1), 62, 14, 1); // selector 2//ini=2-->16++
    }
};