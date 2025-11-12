#pragma once
#include <core/remote_devices/views/remote_devices_view.h>
#include <infrastructure/display.h>
#include <core/remote_devices/icons/pedal_device.h>
#include <core/main/icons/device.h>


class AvailableDevicesWindow : public RemoteDevicesView
{
private:
    Display &display;
    LinkedDevicesData devices_linked;
    DevicesListData devices_listed;

    void setDeviceSelector(int typ_selector = 0)
    {

        display.drawFrame(67, 10, 28, 28, 3);
        display.drawBitmap(68, 12, WIDTH, HEIGHT, DEVICE_BITS);

        display.setFont(u8g2_font_lubBI10_te);

        typ_selector == 0 ? display.drawText(101, 29, "L") : display.drawText(101, 29, "S");

        display.drawFrame(97, 16, 18, 16, 1);

        display.drawTriangle(96, 14, 106, 9, 116, 14);
        display.drawTriangle(98, 34, 106, 38, 114, 34);
    }

    void setDeviceSelected(int typ_selector = 0)
    {

        display.drawFrame(67, 10, 28, 28, 3);
        display.drawBitmap(68, 12, WIDTH, HEIGHT, DEVICE_BITS);

        display.setFont(u8g2_font_lubBI12_te);

        display.drawFrame(97, 10, 18, 28, 3);
        // display.drawBox(100, 11, 14, 26);
        // display.setColor(0);
        typ_selector == 0 ? display.drawText(100, 31, "L") : display.drawText(100, 31, "S");
    }

    void setPedalDevice()
    {
        display.drawFrame(67, 10, 48, 28, 3);
        display.drawBitmap(69, 11, 45, 26, PEDAL_DEVICE_BITS);
    }

public:
    explicit AvailableDevicesWindow(Display &disp, DevicesListData dev_list, LinkedDevicesData dev_link) : RemoteDevicesView(disp, dev_list), display(disp), devices_linked(dev_link), devices_listed(dev_list) {}

    void show(int dev_selector = 0)
    {
        RemoteDevicesView::show(1, dev_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);

        display.setFont(u8g_font_6x10);
        display.drawFrame(13, 10, 48, 28, 3);
        display.drawText(18, 27, devices_listed.linked_devices[dev_selector].name);

        display.drawBox(12, 41, 50, 11);
        display.drawBox(66, 41, 50, 11);
        display.drawFrame(11, 40, 52, 13, 3);
        display.drawFrame(65, 40, 52, 13, 3);

        // setPedalDevice();
        // setDeviceSelected();
        setDeviceSelector();
        display.setColor(0);
        display.setFont(u8g_font_6x10);
        display.drawText(20, 50, "<BACK>");
        display.drawText(70, 50, "<ENTER>");
    }
};