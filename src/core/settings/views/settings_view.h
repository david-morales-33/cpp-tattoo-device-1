#pragma once
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>
#include <core/settings/icons/clock.h>
#include <core/settings/icons/sound.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/data_transfer_objects/date_time_format.h>
#include <core/settings/icons/sound.h>
#include <core/settings/icons/clock.h>
#include <core/settings/icons/calendar.h>

class SettingsView
{
private:
    Display &display;

public:
    explicit SettingsView(Display &_display ) : display(_display)
    {
    }

    void show(int selector = 0)
    {
        display.setColor(1);
        display.setFontMode(1);
        display.drawLine(0, 16, 128, 16);
        display.drawLine(60, 16, 60, 64);

        display.drawFrame(0, 0, 128, 64, 3);
        display.drawBox(1, 1, 126, 14);

        display.setFont(u8g2_font_courB10_tf);
        display.setColor(0);
        display.setCursor(60, 12);

        display.drawText(30, 12, "SETTINGS");
        display.setColor(1);
        display.setFont(u8g_font_5x7);
        display.drawText(10, 27, "SOUND");
        display.drawText(10, 38, "CLOCK");
        display.drawText(10, 49, "DATE");
        display.drawText(10, 60, "RESET");

        display.drawFrame(2, ((selector * 11) + 18), 57, 11, 2);

        display.drawText(64, 27, "ON");
        display.drawText(63, 38, "05:06 PM");
        display.drawText(63, 49, "07/12/2025");
        display.drawText(64, 60, "ALL");
    }
};
