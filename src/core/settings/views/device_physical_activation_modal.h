#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/settings/interfaces/physical_device_activation.h>

class DevicesPhysicalActivationModal : public SettingsView
{
private:
    Display &display;

public:
    explicit DevicesPhysicalActivationModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show(int side_selector = 0, int value_selector = 0, PhysicalDeviceActivation activation = PhysicalDeviceActivation::CONTINUOUS)
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
        activation ==PhysicalDeviceActivation::CONTINUOUS ? display.drawText(33, 36, "CONTINUOUS") : //
        activation ==PhysicalDeviceActivation::NO_PEDAL ?display.drawText(38, 36, "NO PEDAL")://
        display.drawText(45, 36, "PULSES");
    }
};