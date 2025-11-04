#pragma once 
#include <infrastructure/display.h>
#include <infrastructure/icons_size.h>
#include <core/device_configuration/icons/device.h>
#include <persistence/device_configuration/data.h>

class DeviceConfigurationView
{
private:
    Display &display;
    VoltageData data;

    void setDevices(int selector)
    {
        int mode[2] = {2, 1};

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

    void setValues(int selector)
    {
        display.setFontMode(1);
        display.setColor(0);
        display.setFont(u8g_font_5x8);
        display.drawText(69, 11, "VAL1");
        display.drawText(69, 27, "VAL2");
        display.drawText(69, 43, "VAL3");
        display.drawText(69, 59, "VAL4");

        display.setCursor(100, 11);
        display.print(String(data.voltages[selector][0]));
        display.setCursor(100, 27);
        display.print(String(data.voltages[selector][1]));
        display.setCursor(100, 43);
        display.print(String(data.voltages[selector][2]));
        display.setCursor(100, 59);
        display.print(String(data.voltages[selector][3]));
    }


public:
    explicit DeviceConfigurationView(Display &disp, VoltageData volt) : display(disp), data(volt) {}

    void show(int dev_selector = 0)
    {
        // maquinas
        setDevices(dev_selector);
        // voltajes
        setValues(dev_selector);

    }
};