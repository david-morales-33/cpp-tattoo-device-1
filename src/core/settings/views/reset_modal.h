#pragma once
#include <infrastructure/display.h>
#include <core/settings/views/settings_view.h>
#include <core/settings/interfaces/reset_options.h>
#include <core/settings/data_transfer_objects/reset_selector.h>

class ResetModal : public SettingsView
{

private:
    Display &display;

public:
    explicit ResetModal(Display &_display) : SettingsView(_display), display(_display) {};

    void show(int side_selector, int value_selector, const ResetSelector &reset_selector)
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
        reset_selector.getReset() == ResetOptions::DEVICES ? display.drawText(42, 36, "DEVICES") : display.drawText(54, 36, "ALL");
    }
};