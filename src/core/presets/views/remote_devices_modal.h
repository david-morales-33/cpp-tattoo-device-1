#pragma once
#include <core/shared/data_transfer_objects/counter.h>
#include <infrastructure/display.h>

class RemoteDevicesModal : public PresetsSelector
{
private:
    Display &display;

public:
    explicit RemoteDevicesModal(Display &_display) : display(_display), PresetsSelector(_display) {}

    void show(int device_selector = 0, int option_selector = 0, int counter = 0)
    {
        PresetsSelector::show(device_selector, option_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(17, 7, 96, 50);
        display.setColor(1);
        display.drawFrame(17, 7, 96, 50);
        display.drawFrame(20, 10, 90, 44, 2);
        display.setFont(u8g_font_5x7);
        display.drawText(33, 30, "Waiting for");
    }

private:
    void setWaitingMessage(Counter &counter)
    {
        if (counter.getCount() == 3)
            display.drawText(23, 40, "remote devices");
        else if (counter.getCount() == 6)
            display.drawText(23, 40, "remote devices.");
        else if (counter.getCount() == 9)
            display.drawText(23, 40, "remote devices..");
        else if (counter.getCount() == 12)
        {
            display.drawText(23, 40, "remote devices...");
            counter.reset();
        }
    }
};