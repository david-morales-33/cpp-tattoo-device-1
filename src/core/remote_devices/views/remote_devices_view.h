#pragma once
#include <infrastructure/display.h>
#include <persistence/linked_devices/data.h>
#include <persistence/linked_devices/data.h>
#include <core/remote_devices/icons/empty_box.h>
#include <core/remote_devices/icons/empty_file.h>

class RemoteDevicesView
{
private:
    Display &display;
    DevicesListData devices;

    void setDevicesToPair(int position = 0, const char *txt = "NONE")
    {
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

    void setSelector(int typ_selector = 0, int dev_selector = 0)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawFrame(((typ_selector * 65) + 2), ((16 * dev_selector) + 17), 59, 14, 1); // selector 2//ini=2-->16++
    }

    void setEmptyLinkedDevices()
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x7);
        display.drawText(74, 37, "Waiting for");
        display.drawText(72, 47, "devices...");
    }
    
    void setEmptyAvailableDevices()
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawBitmap(16, 19, 27, 27, EMPTY_BOX_BITS);
        // display.drawBitmap(16, 19, 28, 28, EMPTY_FILE_BITS);
        display.setFont(u8g_font_5x7);
        display.drawText(8, 57, "No devices");
    }

public:
    explicit RemoteDevicesView(Display &disp, DevicesListData dev) : display(disp), devices(dev) {}
    void show(int typ_selector = 0, int dev_selector = 0)
    {
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
        display.drawText(13, 11, "PARIED");
        display.drawText(75, 11, "DEVICES");

        //setEmptyLinkedDevices();
        //setEmptyAvailableDevices();

        // for (int i = 0; i < devices.available_devices.size(); i++)
        //     setDevicesToPair(i, devices.available_devices[i].name);

        // for (int i = 0; i < devices.linked_devices.size(); i++)
        //     setLinkedDevices(i, devices.linked_devices[i].name);

        //setSelector(typ_selector, dev_selector);
    }
};
