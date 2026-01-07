#pragma once
#include <infrastructure/display.h>
#include <infrastructure/icons_size.h>
#include <core/presets/icons/device.h>

class PresetsView
{
private:
    Display &display;

    void setDevices(int selector)
    {
        int mode[2] = {2, 1};
        // int selector = data.getType() == VoltageType::LINE ? 0 : 1;

        display.setColor(1);
        display.setColor(1);
        display.drawBitmap(3, 3, WIDTH, HEIGHT, DEVICE_CONFIGURATION_BITS); // 35,4
        display.drawFrame(2, 2, 28, 27, 3);
        display.drawLine(4, 27, 27, 27);
        display.drawBitmap(3, 36, WIDTH, HEIGHT, DEVICE_CONFIGURATION_BITS); // 3,4
        display.drawFrame(2, 35, 28, 27, 3);
        display.drawLine(4, 60, 28, 60);
        // interfaz de maquinas
        display.setFontMode(1);
        display.setColor(mode[selector]); // 2-1
        display.drawFrame(0, 0, 62, 31, 3);
        display.setColor(mode[1 - selector]); // 2-1
        display.drawFrame(0, 33, 62, 31, 3);

        display.setColor(1);
        display.drawFrame(32, 2, 28, 27, 3);
        display.drawFrame(32, 35, 28, 27, 3);

        display.drawBox(33, 3, 26, 25);
        display.drawBox(33, 36, 26, 25);

        display.drawFrame(64, 0, 64, 64, 3);
        display.drawBox(65, 1, 62, 62);

        display.setColor(0);
        display.setFont(u8g2_font_lubBI18_te);
        display.drawText(37, 24, "L");
        display.drawText(37, 58, "S");
        // selector
        display.setFontMode(1);
        display.setColor(2);
        display.drawBox(1, (1 + (selector * 33)), 60, 29); // selector 1 // x=1/x=34
    }

    void setValues()
    {
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g_font_5x8);
        display.drawText(69, 11, "VOLTAGES");
        display.drawText(69, 27, "DEVICE BOOT");
        display.drawText(69, 43, "ACTIVATION");
        display.drawText(69, 59, "REMOTE DEV");
    }

public:
    explicit PresetsView(Display &disp) : display(disp) {}

    void show(int selector = 0)
    {
        // maquinas
        setDevices(selector);
        // voltajes
        setValues();
    }
};