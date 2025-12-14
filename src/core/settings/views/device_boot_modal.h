#pragma once
#include <infrastructure/display.h>
#include <core/settings/views/settings_view.h>
#include <core/settings/interfaces/device_boot.h>
#include <core/settings/data_transfer_objects/boot_selector.h>

class DeviceBootModal : public SettingsView
{

private:
    Display &display;

public:
    explicit DeviceBootModal(Display &_display) : SettingsView(_display), display(_display) {};

    void show(int side_selector , int value_selector , const BootSelector &boot_selector)
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
        boot_selector.getBoot() == DeviceBoot::INSTANT_POWER ? display.drawText(42, 36, "INSTANT") :
        boot_selector.getBoot() == DeviceBoot::SOFT_START ? display.drawText(52, 36, "SOFT") :
        boot_selector.getBoot() == DeviceBoot::LINEAR_RAMP ? display.drawText(46, 36, "LINEAR") :
        display.drawText(45, 36, "CUSTOM");
    }
};