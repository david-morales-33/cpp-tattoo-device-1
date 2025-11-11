#pragma once
#include <core/linked_devices/views/linked_devices_view.h>
#include <infrastructure/display.h>
#include <core/linked_devices/icons/pedal_device.h>

class AvailableDevicesWindow : public LinkedDevicesView
{
private:
    Display &display;
    LinkedDevicesData devices_linked;
    DevicesListData devices_listed;

    void setDeviceSelector(int typ_dev_selector = 0)
    {

        display.drawFrame(69, 10, 28, 28, 3);
        display.drawBitmap(70, 12, WIDTH, HEIGHT, DEVICE_BITS);

        display.setFont(u8g2_font_lubBI10_te);

        typ_dev_selector == 0? 
        display.drawText(102, 29, "L"):
        display.drawText(102, 29, "S");

        display.drawFrame(99, 16, 16, 16, 1);

        display.drawTriangle(97, 14, 107, 9, 117, 14);
        display.drawTriangle(99, 34, 107, 38, 115, 34);
    }

    void setPedalDevice()
    {
        display.drawFrame(69, 10, 46, 28, 3);
        display.drawBitmap(70, 11, 45, 26, PEDAL_DEVICE_BITS);
    }

public:
    explicit AvailableDevicesWindow(Display &disp, DevicesListData dev_list, LinkedDevicesData dev_link) : LinkedDevicesView(disp, dev_list), display(disp), devices_linked(dev_link), devices_listed(dev_list) {}

    void show(int dev_selector = 0)
    {
        LinkedDevicesView::show(1, dev_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);

        display.setFont(u8g_font_6x10);
        display.drawFrame(13, 10, 46, 28, 3);
        display.drawText(18, 27, devices_listed.linked_devices[dev_selector].name);

        display.drawBox(12, 41, 48, 11);
        display.drawBox(68, 41, 48, 11);
        display.drawFrame(11, 40, 50, 13, 3);
        display.drawFrame(67, 40, 50, 13, 3);

        setPedalDevice();

        display.setColor(0);
        display.setFont(u8g_font_6x10);
        display.drawText(16, 50, "<BACK>");
        display.drawText(73, 50, "<ENTER>");
    }
};