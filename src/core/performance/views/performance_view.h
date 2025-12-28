#pragma once
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>

class PerformanceView
{
private:
    Display &display;

public:
    explicit PerformanceView(Display &_display) : display(_display)
    {
    }

    void drawGraf()
    {
        display.drawLine(77, 60, 124, 60);
        display.drawLine(77, 19, 77, 60);
        display.setFont(u8g_font_4x6);

        display.drawText(95, 26, "RECORDS");
        display.drawText(80, 26, "%");
        display.drawText(120, 58, "T");

        display.drawBox(80, 30, 3, 30);
        display.drawBox(84, 40, 3, 20);
        display.drawBox(88, 35, 3, 25);
        display.drawBox(92, 45, 3, 15);
        display.drawBox(96, 45, 3, 15);
    }

    void show()
    {
        display.setColor(1);
        display.setFontMode(1);
        display.drawLine(0, 16, 128, 16);
        display.drawLine(74, 16, 74, 64);

        display.drawFrame(0, 0, 128, 64, 3);
        display.drawBox(1, 1, 126, 14);
        display.setFont(u8g2_font_courB10_tf);
        display.setColor(0);
        display.setCursor(60, 12);

        display.drawText(15, 12, "PERFORMANCE");
        display.setColor(1);
        display.setFont(u8g_font_5x7);

        display.drawText(3, 27, "START");
        display.drawText(3, 38, "END  ");
        display.drawText(2, 49, "TOTAL");
        display.drawText(3, 60, "DEV  ");

        display.drawText(31, 27, "00:00:00");
        display.drawText(31, 38, "00:00:00");
        display.drawText(31, 49, "00:00:00");
        display.drawText(31, 60, "00:00:00");
        drawGraf();
    }
};
