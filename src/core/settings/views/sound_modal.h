#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/sound_selector.h>

class SoundModal : public SettingsView
{
private:
    Display &display;

public:
    explicit SoundModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show(int side_selector = 0, int value_selector = 0, const SoundSelector &sound_selector)
    {
        SettingsView::show(side_selector, value_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(33, 18, 62, 28);
        display.setColor(1);
        display.drawFrame(33, 18, 62, 28);
        display.drawTriangle(36, 32, 42, 26, 42, 38);
        display.drawTriangle(92, 32, 86, 26, 86, 38);
        display.setFont(u8g2_font_courB10_tf);
        sound_selector.getSound() == SoundState::OFF ? display.drawText(51, 37, "OFF") : display.drawText(56, 37, "ON");
    }
};
