#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_selector.h>

class DeviceConfigurationModal : public DeviceConfigurationSelector
{
private:
    Display &display;

public:
    explicit DeviceConfigurationModal(Display &_display) : DeviceConfigurationSelector(_display), display(_display) {};
    void show(const VoltageGroup &data, const float value, int val_selector = 0, int uni_selector = 0)
    {

        DeviceConfigurationSelector::show(data, val_selector);

        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(22, 7, 86, 50);
        display.setColor(1);
        display.drawFrame(22, 7, 86, 50);
        display.setFont(u8g2_font_logisoso22_tf);
        value < 10 ? display.setCursor(38, 43) : display.setCursor(28, 43); // 2 unidad => x=28

        display.setColor(2);
        display.print(String(value));

        if (uni_selector == 0)
        {
            display.drawTriangle(37, 18, 53, 18, 45, 10); // unidad x_=37;x_2=53;x_3=45// decimal  =>
            display.drawTriangle(38, 46, 52, 46, 45, 53);
        }
        else if ((uni_selector == 1) && (value < 10))
        {
            display.drawTriangle(69, 18, 85, 18, 77, 10);
            display.drawTriangle(70, 46, 84, 46, 77, 53);
        }
        else
        {
            display.drawTriangle(74, 18, 90, 18, 82, 10); // unidad x_=74;x_2=90;x_3=82// decimal  =>
            display.drawTriangle(75, 46, 89, 46, 82, 53);
        }
    }
};