#pragma once
#include <infrastructure/display.h>
#include <persistence/linked_devices/data.h>

class LinkedDevicesView
{
private:
    Display &display;

public:
    explicit LinkedDevicesView(Display &disp) : display(disp) {}
    void show()
    {
        const char *test_dev[] = {"MACH_DEV_1", "MACH_DEV_2", "PED_DEV_1"};
        const char *test_link[] = {"MACH_DEV_3"};
        SelectorData selector_test;

        display.setFontMode(1);
        display.setColor(1);
        display.drawFrame(0, 0, 128, 64, 3);
        display.drawBox(1, 1, 62, 14);
        display.drawBox(65, 1, 62, 14);

        display.drawLine(62, 15, 62, 64);
        display.drawLine(65, 15, 65, 64);

        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g_font_6x10);
        display.drawText(13, 11, "LINKED");
        display.drawText(75, 11, "DEVICES");

        for (int i = 0; i < 3; i++)
            setDevicesToPair(i, test_dev[i]);

        for (int i = 0; i < 1; i++)
            setLinkedDevices(i, test_link[i]);

        selector_test.selector_x = 1;
        selector_test.selector_y = 0;
        setSelector(selector_test);
    }

    void setDevicesToPair(int position = 0, const char *txt = "NONE")
    { // 16++

        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.setCursor(69, ((position * 16) + 27));
        display.print(txt);
    }

    void setLinkedDevices(int position = 0, const char *txt = "NONE")
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.setCursor(4, ((position * 16) + 27));
        display.print(txt);
    }

    void setSelector(SelectorData selector)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawFrame(((selector.selector_x * 65) + 2), ((16 * selector.selector_y) + 17), 59, 14, 1); // selector 2//ini=2-->16++
    }
};
