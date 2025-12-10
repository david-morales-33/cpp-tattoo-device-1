#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/settings/interfaces/sound_state.h>

class PedalModal : public SettingsView
{
private:
    Display &display;

public:
    explicit PedalModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show()
    {
        SettingsView::show();
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(20, 18, 84, 28);
        display.setColor(1);
        display.drawFrame(20, 18, 84, 28);
        display.drawTriangle(24, 32,  30, 26,  30, 38);
        display.drawTriangle(100, 32,  94, 26,  94, 38);
        display.setFont(u8g2_font_courB10_tf);
        // state == SoundState::OFF ? display.drawText(51, 37, "OFF") : display.drawText(56, 37, "ON");
    }
};