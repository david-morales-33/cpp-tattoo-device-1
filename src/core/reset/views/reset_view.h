#pragma once

#include <infrastructure/display.h>
#include <core/main/views/main_view.h>
#include <persistence/main/data.h>

class ResetView : public MainView
{

private:
    Display &display;

public:
    explicit ResetView(Display &disp) : MainView(disp), display(disp) {};

    void show(SliderData slider)
    {
        MainView::show(slider);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);
        display.setFont(u8g_font_5x8);
        display.drawText(24, 18, "ARE YOU SURE TO");
        display.drawText(38, 30, "CONTINUE?");
        display.drawFrame(12, 36, 50, 17, 3);
        display.drawFrame(66, 36, 50, 17, 3);
        display.drawBox(13, 37, 48, 15);
        display.drawBox(67, 37, 48, 15);

        display.setColor(0);
        display.setFont(u8g_font_6x13);
        display.drawText(16, 49, "<ENTER>");
        display.drawText(73, 49, "<BACK>");
        display.setColor(1);
    }
};