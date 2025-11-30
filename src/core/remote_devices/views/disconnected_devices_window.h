#pragma once
#include <core/remote_devices/views/remote_devices_view.h>
#include <infrastructure/display.h>
#include <core/remote_devices/icons/pedal_device.h>
#include <core/main/icons/device.h>
#include <infrastructure/icons_size.h>

class DisconnectedDevicesWindow : public RemoteDevicesView
{
private:
    Display &display;

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
    explicit DisconnectedDevicesWindow(Display &_display) : display(_display), RemoteDevicesView(_display) {}
    void show(const std::vector<Device> &disconnected_devices,
              const std::vector<Device> &connected_devices,
              int case_device = 6,
              int device_selector = 0)
    {
        RemoteDevicesView::show(disconnected_devices, connected_devices, case_device, device_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);

        display.setFont(u8g_font_6x10);
        display.drawFrame(13, 10, 48, 28, 3);
        display.drawText(18, 27, disconnected_devices[device_selector].getName());

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