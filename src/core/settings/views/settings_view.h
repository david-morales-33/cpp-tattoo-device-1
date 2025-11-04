#pragma once
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>
#include <core/settings/icons/clock.h>
#include <core/settings/icons/sound.h>
#include <persistence/main/data.h>

class SettingsView : public MainView
{
private:
    Display &display;
    const char *tittle;

public:
    explicit SettingsView(Display &disp, const char *txt) : MainView(disp), display(disp), tittle(txt) {}

    void show(SliderData slider ,int selector = 0)
    {
        MainView::show(slider);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(32, 5, 66, 54);
        display.setColor(1);
        display.drawFrame(31, 5, 66, 54);
        display.drawFrame(36, 30, 24, 24, 3);
        display.drawFrame(68, 30, 24, 24, 3);
        display.setColor(1);
        display.setBitmapMode(1);
        display.drawBitmap(38, 32, 20, 20, SETTING_CLOCK_BITS);
        display.drawBitmap(70, 32, 20, 20, SOUND_BITS);
        display.setColor(2);
        display.setFont(u8g2_font_courB10_tf);
        display.drawBox(((selector * 32) + 34), 28, 28, 28); // primer valor 34/66
        display.setCursor(42, 21);
        display.print(tittle);
    }
};
