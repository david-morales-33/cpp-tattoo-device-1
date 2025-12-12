#pragma once
#include <core/settings/views/settings_view.h>
#include <core/settings/data_transfer_objects/date_selector.h>

class DateModal : public SettingsView
{

private:
    Display &display;

public:
    explicit DateModal(Display &_display) : SettingsView(_display), display(_display) {}

    void show(int side_selector = 0, int value_selector = 0, const DateSelector &date_selector)
    {
        SettingsView::show(side_selector, value_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(10, 7, 108, 50);
        display.setColor(1);
        display.drawFrame(10, 7, 108, 50);
        display.drawFrame(14, 21, 23, 22, 3);
        display.drawFrame(43, 21, 23, 22, 3);
        display.drawFrame(72, 21, 43, 22, 3);
        display.drawBox(15, 22, 21, 20);
        display.drawBox(44, 22, 21, 20);
        display.drawBox(73, 22, 41, 20);

        display.setColor(0);
        display.setFont(u8g2_font_logisoso16_tf);

        display.setCursor(15, 40);
        display.print(date_selector.getDayFormated().c_str());

        display.setCursor(44, 40);
        display.print(date_selector.getMonthFormated().c_str());

        display.setCursor(74, 40);
        display.print(date_selector.getYearFormated().c_str());

        display.setFontMode(1);
        display.setColor(1);

        if (date_selector.getSelector() == 0)
        {
            display.drawTriangle(17, 18, 33, 18, 25, 10); // unidad x_=37;x_2=53;x_3=45// decimal  =>
            display.drawTriangle(18, 46, 32, 46, 25, 53);
        }
        else if (date_selector.getSelector() == 1)
        {
            display.drawTriangle(47, 18, 63, 18, 55, 10); // unidad x_=37;x_2=53;x_3=45// decimal  =>
            display.drawTriangle(48, 46, 62, 46, 55, 53);
        }
        else if (date_selector.getSelector() == 2)
        {
            display.drawTriangle(86, 18, 102, 18, 94, 10); // unidad x_=37;x_2=53;x_3=45// decimal  =>
            display.drawTriangle(87, 46, 101, 46, 94, 53);
        }
    }
};