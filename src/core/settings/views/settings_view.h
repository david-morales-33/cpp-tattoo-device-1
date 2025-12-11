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
    explicit SettingsView(Display &_display) : display(_display)
    {
    }

    void show(int side_selector = 0, int value_selector = 0)
    {
        display.setColor(1);
        display.setFontMode(1);
        display.drawLine(0, 16, 128, 16);
        display.drawLine(64, 16, 64, 64);

        display.drawFrame(0, 0, 128, 64, 3);
        display.drawBox(1, 1, 126, 14);

        display.setFont(u8g2_font_courB10_tf);
        display.setColor(0);
        display.setCursor(60, 12);

        display.drawText(30, 12, "SETTINGS");
        display.setColor(1);
        display.setFont(u8g_font_5x7);
        display.drawText(6, 27, "SOUND");
        display.drawText(6, 38, "CLOCK");
        display.drawText(6, 49, "DATE");
        display.drawText(6, 60, "RESET");

        display.drawFrame(((side_selector * 64) + 2), ((value_selector * 11) + 18), 60, 11, 2);

        display.drawText(70, 27, "PEDAL DEV F");
        display.drawText(70, 38, "PEDAL DEV R");
        display.drawText(70, 49, "BOOT");
        // display.drawText(68, 60, "ALL");
    }
};
