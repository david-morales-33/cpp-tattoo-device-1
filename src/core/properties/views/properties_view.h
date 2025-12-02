#pragma once
#include <infrastructure/display.h>
#include <core/properties/icons/clock.h>
#include <core/properties/icons/temperature.h>
#include <infrastructure/icons_size.h>
#include <core/properties/data_transfer_object/timer_group.h>
#include <string>

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
    void setClock(const TimerGroup &timer_group)
    {
        std::string start_time = std::string("START") + timer_group.resolve(TimeType::START_TIME).getTime();
        std::string end_time = std::string("END") + timer_group.resolve(TimeType::END_TIME).getTime();
        std::string total_time = std::string("TOTAL") + timer_group.resolve(TimeType::TOTAL_TIME).getTime();
        std::string device_time = std::string("DEVICE") + timer_group.resolve(TimeType::DEVICE_TIME).getTime();

        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g2_font_courB10_tf);
        display.setCursor(60, 12);
        display.drawText(60, 12, "TIME");
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.drawText(40, 25, start_time.c_str());
        display.drawText(40, 37, end_time.c_str());
        display.drawText(40, 49, total_time.c_str());
        display.drawText(40, 61, device_time.c_str());
    }

public:
    explicit PropertiesView(Display &disp) : display(disp) {};

    void show(const TimerGroup &timer_group, int position = 0)
    {
        setElements();
        position == 0 ? setTemperature() : setClock(timer_group);
    }
};