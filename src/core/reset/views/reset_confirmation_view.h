#pragma once

#include <infrastructure/display.h>
#include <core/main/views/main_view.h>
#include <persistence/main/data.h>

class ResetConfirmationView : public MainView
{

private:
    Display &display;

public:
    explicit ResetConfirmationView(Display &disp) : MainView(disp), display(disp) {};

    void show(SliderData slider)
    {
        MainView::show(slider);
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g2_font_courB08_tf);
        display.drawBox(38, 24, 54, 20);
        display.setColor(1);
        display.drawFrame(37, 23, 56, 22);
        display.drawText(52, 37, "DONE!");
        display.setColor(1);
    }
};