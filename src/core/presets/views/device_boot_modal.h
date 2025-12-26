#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_selector.h>
#include <core/presets/data_transfer_objects/boot_selector.h>

class DeviceBootModal : public PresetsSelector
{

private:
    Display &display;

public:
    explicit DeviceBootModal(Display &_display) : PresetsSelector(_display), display(_display) {};

    void show(const BootSelector &boot_selector, int device_selector = 0, int option_selector = 0)
    {
        PresetsSelector::show(device_selector, option_selector);
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