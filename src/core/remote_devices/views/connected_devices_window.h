#pragma once
#include <core/remote_devices/views/remote_devices_view.h>
#include <infrastructure/display.h>

class ConnectedDevicesWindow : public RemoteDevicesView
{
private:
    Display &display;

public:
    explicit ConnectedDevicesWindow(Display &disp) : RemoteDevicesView(disp), display(disp) {}

    void show(
        std::vector<Device> disconnected_devices,
        std::vector<Device> connected_devices,
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
        display.drawText(24, 18, "REMOVE DEVICE?");
        display.setFont(u8g_font_5x8);
        display.drawText(38, 30, connected_devices[device_selector].getName());

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