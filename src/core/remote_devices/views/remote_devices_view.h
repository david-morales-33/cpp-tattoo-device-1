#pragma once
#include <vector>
#include <infrastructure/display.h>
#include <core/remote_devices/icons/empty_box.h>
#include <core/remote_devices/icons/empty_file.h>
#include <core/remote_devices/data_transfer_objects/device.h>

class RemoteDevicesView
{
private:
    Display &display;

    void setDevicesToPair(int position = 0, const char *txt = "NONE")
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.setCursor(74, ((position * 15) + 27));
        display.print(txt);
    }

    void setLinkedDevices(int position = 0, const char *txt = "NONE")
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x8);
        display.setCursor(6, ((position * 15) + 27));
        display.print(txt);
    }

    void setSelector(int typ_selector = 0, int dev_selector = 0)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawFrame(((typ_selector * 65) + 2), ((15 * dev_selector) + 17), 59, 14, 1); // selector 2//ini=2-->16++
    }

    void setEmptyConnectedDevices()
    {
        display.setFontMode(1);
        display.setColor(1);
        display.drawBitmap(16, 19, 27, 27, EMPTY_BOX_BITS);
        // display.drawBitmap(16, 19, 28, 28, EMPTY_FILE_BITS);
        display.setFont(u8g_font_5x7);
        display.drawText(8, 57, "No devices");
    }

    void setEmptyDisconnectedDevices()
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g_font_5x7);
        display.drawText(70, 37, "Waiting for");
        display.drawText(72, 47, "devices...");
    }

public:
    explicit RemoteDevicesView(Display &disp) : display(disp) {}
    void show(
        std::vector<Device> disconnected_devices,
        std::vector<Device> connected_devices,
        int case_device = 6,
        int device_selector = 0)
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

                if (case_device == 1)
        { // Elements full - set on the conneted devices
            for (int i = 0; i < disconnected_devices.size(); i++)
                setDevicesToPair(i, disconnected_devices[i].getName());

            for (int i = 0; i < connected_devices.size(); i++)
                setLinkedDevices(i, connected_devices[i].getName());

            setSelector(0, device_selector);
        }

        else if (case_device == 2)
        { // Elements full - set on the disconneted devices
            for (int i = 0; i < disconnected_devices.size(); i++)
                setDevicesToPair(i, disconnected_devices[i].getName());

            for (int i = 0; i < connected_devices.size(); i++)
                setLinkedDevices(i, connected_devices[i].getName());

            setSelector(1, device_selector);
        }

        else if (case_device == 3)
        { // Only Connected Devices - set selector on the Connected devices
            setEmptyDisconnectedDevices();

            for (int i = 0; i < connected_devices.size(); i++)
                setLinkedDevices(i, connected_devices[i].getName());

            setSelector(0, device_selector);
        }
        else if (case_device == 4)
        { // Only Disconnected Devices - set selector on the disconnected devices
            setEmptyConnectedDevices();

            for (int i = 0; i < disconnected_devices.size(); i++)
                setDevicesToPair(i, disconnected_devices[i].getName());

            setSelector(1, device_selector);
        }
        else
        { // Emtpy elements - No selector
            setEmptyConnectedDevices();
            setEmptyDisconnectedDevices();
        }
    }
};
