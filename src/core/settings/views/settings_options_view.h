#pragma once
#include <core/settings/views/settings_view.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/data_transfer_objects/date_time_format.h>
#include <infrastructure/display.h>

class SettingsOptionsView : public MainView
{

private:
    Display &display;

public:
    explicit SettingsOptionsView(Display &disp) : MainView(disp), display(disp) {}
    void show(const Slider &slider, const DateTimeFormat &data, int selector = 0)
    {
        MainView::show(slider, data);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(30, 5, 70, 54);
        display.setColor(1);
        display.drawFrame(29, 5, 70, 54);
        display.setFont(u8g2_font_courB10_tf);
        display.setCursor(33, 21);
        display.print("OPTIONS");

        display.setFont(u8g_font_6x10);
        display.drawText(50, 39, "CLOCK");
        display.drawText(53, 53, "DATE");
        display.setColor(2);
        display.drawFrame(34, ((selector * 14) + 29), 60, 13, 3);
        display.drawBox(35, ((selector * 14) + 30), 58, 11);
        display.setColor(1);
    }
};