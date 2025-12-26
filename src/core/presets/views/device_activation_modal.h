#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_selector.h>
#include <core/presets/interfaces/device_activation.h>
#include <core/presets/data_transfer_objects/activation_selector.h>

class DeviceActivationModal : public PresetsSelector
{

private:
    Display &display;

public:
    explicit DeviceActivationModal(Display &_display) : PresetsSelector(_display), display(_display) {};

    void show(const ActivationSelector &activation_selector, int device_selector = 0, int option_selector = 0)
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
        activation_selector.getActivation()==DeviceActivation::CONTINUOUS ? display.drawText(33, 36, "CONTINUOUS") : //
        activation_selector.getActivation() ==DeviceActivation::NO_PEDAL ?display.drawText(38, 36, "NO PEDAL")://
        display.drawText(45, 36, "PULSES");
    }
};