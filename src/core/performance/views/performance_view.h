#pragma once
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>
#include <core/performance/data_transfer_objects/performance.h>
#include <string>

class PerformanceView
{
private:
    Display &display;

public:
    explicit PerformanceView(Display &_display) : display(_display)
    {
    }

    void drawGrafBar(int position, float record)
    {
        int x = 80 + (position * 4);
        int length_bar = 30 * (record / 100);

        display.drawBox(x, (60 - length_bar), 3, length_bar);
    }

    void drawGraf(const std::vector<PerformanceRecord> &record_list)
    {
        display.drawLine(77, 60, 124, 60);
        display.drawLine(77, 19, 77, 60);
        display.setFont(u8g_font_4x6);

        display.drawText(95, 26, "RECORDS");
        display.drawText(80, 26, "%");
        display.drawText(120, 58, "T");

        for (int i = 0; i < record_list.size(); i++)
            drawGrafBar(i, record_list[i].getPerformance());
    }

    void show(const Performance &performance, const std::vector<PerformanceRecord> &record_list)
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

        display.drawText(31, 27, performance.getStartTime().getTime());
        display.drawText(31, 38, performance.getEndTime().getTime());
        display.drawText(31, 49, performance.getTotalTime().getTime());
        display.drawText(31, 60, performance.getDeviceTime().getTime());
        drawGraf(record_list);
    }
};
