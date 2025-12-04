#pragma once
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>
#include <core/settings/icons/clock.h>
#include <core/settings/icons/sound.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/data_transfer_objects/date_time_format.h>

class SettingsView : public MainView
{
private:
    Display &display;

public:
    explicit SettingsView(Display &disp) : MainView(disp), display(disp)
    {
    }

    void show(const Slider &slider, const DateTimeFormat &data, int selector = 0)
    {
        MainView::show(slider, data);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(32, 5, 66, 54);
        display.setColor(1);
        display.drawFrame(31, 5, 66, 54);
        display.drawFrame(36, 30, 24, 24, 3);
        display.drawFrame(68, 30, 24, 24, 3);
        display.setColor(1);
        display.setBitmapMode(1);
        selector == 0 ? display.drawText(42, 21, "CLOCK") : display.drawText(42, 21, "SOUND");
        display.drawBitmap(38, 32, 20, 20, SETTING_CLOCK_BITS);
        display.drawBitmap(70, 32, 20, 20, SOUND_BITS);
        display.setColor(2);
        display.setFont(u8g2_font_courB10_tf);
        display.drawBox(((selector * 32) + 34), 28, 28, 28); // primer valor 34/66
    }
};
