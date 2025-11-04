#pragma once
#include <core/settings/views/settings_view.h>
#include <infrastructure/display.h>
#include <persistence/main/data.h>

class SoundView : public SettingsView
{
private:
    Display &display;

public:
    explicit SoundView(Display &disp) : SettingsView(disp, "SOUND"), display(disp) {}

    void show(SliderData slider, bool sound_state = HIGH)
    {
        SettingsView::show(slider, 1);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(33, 18, 62, 28);
        display.setColor(1);
        display.drawFrame(33, 18, 62, 28);
        display.drawTriangle(36, 32, 42, 26, 42, 38);
        display.drawTriangle(92, 32, 86, 26, 86, 38);
        display.setFont(u8g2_font_courB10_tf);
        sound_state == LOW ? display.drawText(51, 37, "OFF") : display.drawText(56, 37, "ON");
    }
};
