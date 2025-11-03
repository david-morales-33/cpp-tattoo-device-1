#pragma once
#include <infrastructure/display.h>
#include <core/properties/icons/clock.h>
#include <core/properties/icons/temperature.h>
#include <infrastructure/icons_size.h>

class PropertiesView
{
private:
    Display &display;

    void setElements(int position = 0)
    {
        display.setColor(1);
        display.drawBitmap(3, 3, WIDTH, HEIGHT, TEMPERATURE_BITS); // 35,4
        display.drawFrame(2, 2, 28, 28, 3);
        display.drawBitmap(3, 35, WIDTH, HEIGHT, CLOCK_BITS); // 35,4
        display.drawFrame(2, 34, 28, 28, 3);
        display.setColor(2);
        display.drawBox(0, (32 * position), 32, 32); //+32
        display.setFontMode(1);
        display.setColor(1);
        display.drawLine(34, 16, 128, 16);
        display.drawFrame(34, 0, 94, 64, 3);
        display.drawBox(35, 1, 92, 14);
    }
    void setTemperature()
    {
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g2_font_courB10_tf);
        display.drawText(40, 12, "TEMP-HUME");
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.drawText(36, 25, "Tmax 34C Hmax 12%");
        display.drawText(36, 37, "Tmin 28C Hmin 10%");
        display.drawText(36, 49, "Tpro 31C Hpro 11%");
        display.drawText(36, 61, "Tact 25C Hact 11%");
    }
    void setClock()
    {
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g2_font_courB10_tf);
        display.setCursor(60, 12);
        display.drawText(60, 12, "TIME");
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.drawText(40, 25, "START   02:37:12");
        display.drawText(40, 37, "FINISH  03:20:26");
        display.drawText(40, 49, "TOTAL   01:44:14");
        display.drawText(40, 61, "MACHINE 01:20:01");
    }

public:
    explicit PropertiesView(Display &disp) : display(disp) {};

    void show(int position = 0)
    {
        setElements();
        position == 0 ? setTemperature() : setClock();
    }
};