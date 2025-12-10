#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/settings/interfaces/sound_state.h>

class SoundModal : public SettingsView
{
private:
    Display &display;

public:
    explicit SoundModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show(int selector = 0, SoundState state = SoundState::ON)
    {
        SettingsView::show(selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(33, 18, 62, 28);
        display.setColor(1);
        display.drawFrame(33, 18, 62, 28);
        display.drawTriangle(36, 32, 42, 26, 42, 38);
        display.drawTriangle(92, 32, 86, 26, 86, 38);
        display.setFont(u8g2_font_courB10_tf);
        state == SoundState::OFF ? display.drawText(51, 37, "OFF") : display.drawText(56, 37, "ON");
    }
};
