#pragma once
#include <core/linked_devices/views/linked_devices_view.h>
#include <infrastructure/display.h>

class LinkedDevicesWindow : public LinkedDevicesView
{
private:
    Display &display;
    DevicesListData devices;

public:
    explicit LinkedDevicesWindow(Display &disp, DevicesListData dev) : LinkedDevicesView(disp, dev), display(disp), devices(dev) {}

    void show(int dev_selector = 0)
    {
        LinkedDevicesView::show(0, dev_selector);

        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);
        display.setFont(u8g_font_6x10);
        display.drawText(24, 18, "REMOVE DEVICE?");
        display.setFont(u8g_font_5x8);
        display.drawText(38, 30, devices.linked_devices[dev_selector].name);

        display.drawBox(12, 41, 50, 11);
        display.drawBox(66, 41, 50, 11);
        display.drawFrame(11, 40, 52, 13, 3);
        display.drawFrame(65, 40, 52, 13, 3);

        display.setColor(0);
        display.setFont(u8g_font_6x10);
        display.drawText(20, 50, "<BACK>");
        display.drawText(70, 50, "<ENTER>");
        display.setColor(1);
    }
};