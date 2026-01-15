#pragma once
#include <core/shared/data_transfer_objects/counter.h>
#include <infrastructure/display.h>
#include <core/presets/data_transfer_objects/remote_device_machine.h>
#include <core/shared/data_transfer_objects/remote_device.h>
#include <vector>

class RemoteDevicesModal : public PresetsSelector
{
private:
    Display &display;
    Counter counter;

public:
    explicit RemoteDevicesModal(Display &_display) : display(_display), PresetsSelector(_display), counter(12) {}

    void show(
        const std::vector<RemoteDevice> &remote_device_list,
        const std::vector<RemoteDevice> &remote_device_connected,
        int device_selector = 0,
        int option_selector = 0,
        int remote_devices_selector = 0)
    {
        PresetsSelector::show(device_selector, option_selector);
        if (remote_device_connected.size() != 0)
            setModalConnectedDevice();
        else if (remote_device_list.size() != 0)
            setModalRemoteDevicesList(remote_device_list, remote_devices_selector);
        else
            setWaitingModal();
    }

private:
    void setModalRemoteDevicesList(const std::vector<RemoteDevice> &remote_device_list, int selector = 0)
    {
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(17, 7, 96, 50);
        display.setColor(1);
        display.drawFrame(17, 7, 96, 50);
        // display.drawFrame(19, 9, 92, 28, 2);

        for (int i = 0; i < remote_device_list.size(); i++)
            display.drawText(35, ((12 * i) + 20), remote_device_list[i].getName());

        if (remote_device_list.size() != 0)
            display.drawFrame(21, ((selector * 12) + 11), 88, 12, 2);

        display.drawBox(22, 41, 40, 10);
        display.drawFrame(21, 40, 42, 12, 3);

        display.drawBox(68, 41, 40, 10);
        display.drawFrame(67, 40, 42, 12, 3);

        display.setColor(0);
        display.drawText(27, 49, "<BACK>");
        display.drawText(74, 49, "<PAIR>");
    }

    void setModalConnectedDevice()
    {
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(17, 7, 96, 50);
        display.setColor(1);
        display.drawFrame(17, 7, 96, 50);

        // display.drawFrame(19, 9, 92, 46, 2);

        display.setFont(u8g_font_5x8);
        display.drawText(31, 18, "REMOVE DEVICE?");

        display.drawBox(22, 23, 86, 12);
        display.drawFrame(21, 22, 88, 14, 2);

        display.drawBox(22, 41, 40, 10);
        display.drawFrame(21, 40, 42, 12, 3);

        display.drawBox(68, 41, 40, 10);
        display.drawFrame(67, 40, 42, 12, 3);

        display.setColor(0);
        display.drawText(35, 32, "DEVICE.C4.A6");

        display.drawText(27, 49, "<BACK>");
        display.drawText(71, 49, "<ENTER>");
    }

    void setWaitingModal()
    {
        counter.count();
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(17, 7, 96, 50);
        display.setColor(1);
        display.drawFrame(17, 7, 96, 50);
        display.setFont(u8g_font_5x7);
        display.drawText(33, 30, "Waiting for");
        if (counter.getCount() < 3)
            display.drawText(23, 40, "remote devices");
        else if (counter.getCount() >= 3 && counter.getCount() < 6)
            display.drawText(23, 40, "remote devices.");
        else if (counter.getCount() >= 6 && counter.getCount() < 9)
            display.drawText(23, 40, "remote devices..");
        else if (counter.getCount() >= 9)
        {
            display.drawText(23, 40, "remote devices...");
            if (counter.getCount() > 11)
                counter.reset();
        }
    }
};