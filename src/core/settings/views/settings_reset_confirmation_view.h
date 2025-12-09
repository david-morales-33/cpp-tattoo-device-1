#pragma once
#include <infrastructure/display.h>
#include <core/settings/views/settings_view.h>

class SettingsResetConfirmationView : public SettingsView
{

private:
    Display &display;

public:
    explicit SettingsResetConfirmationView(Display &_display) : SettingsView(_display), display(_display) {};

    void show(int selector = 0)
    {
        SettingsView::show(selector);
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g2_font_courB08_tf);
        display.drawBox(38, 24, 54, 20);
        display.setColor(1);
        display.drawFrame(37, 23, 56, 22);
        display.drawText(52, 37, "DONE!");
        display.setColor(1);
    }
};