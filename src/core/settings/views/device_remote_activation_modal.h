#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <core/settings/interfaces/remote_device_activation.h>
#include <core/settings/data_transfer_objects/remote_activation_selector.h>

class DevicesRemoteActivationModal : public SettingsView
{
private:
    Display &display;

public:
    explicit DevicesRemoteActivationModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show(int side_selector, int value_selector, const RemoteActivationSelector &activation_selector)
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
        activation_selector.getActivation() == RemoteDeviceActivation::NO_PEDAL ? display.drawText(38, 36, "NO PEDAL") : //
            display.drawText(45, 36, "PULSES");
    }
};