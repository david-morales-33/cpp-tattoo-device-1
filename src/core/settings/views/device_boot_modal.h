#pragma once
#include <infrastructure/display.h>
#include <core/settings/views/settings_view.h>
#include <core/settings/interfaces/device_boot.h>

class DeviceBootModal : public SettingsView
{

private:
    Display &display;

public:
    explicit DeviceBootModal(Display &_display) : SettingsView(_display), display(_display) {};

    void show(int side_selector = 0, int value_selector = 0, DeviceBoot boot=DeviceBoot::INSTANT_POWER)
    {
        SettingsView::show(side_selector, value_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(20, 18, 84, 28);
        display.setColor(1);
        display.drawFrame(20, 18, 84, 28);
        display.drawTriangle(24, 32, 30, 26, 30, 38);
        display.drawTriangle(100, 32, 94, 26, 94, 38);
        display.setFont(u8g_font_6x12);
        boot == DeviceBoot::INSTANT_POWER ? display.drawText(42, 36, "INSTANT") :
        boot == DeviceBoot::SOFT_START ? display.drawText(52, 36, "SOFT") :
        boot == DeviceBoot::LINEAR_RAMP ? display.drawText(46, 36, "LINEAR") :
        display.drawText(45, 36, "CUSTOM");
    }
};