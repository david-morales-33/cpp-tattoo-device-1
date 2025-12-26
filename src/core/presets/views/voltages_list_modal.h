#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_selector.h>
#include <core/presets/data_transfer_objects/voltage_list.h>

class VoltagesListModal : public PresetsSelector
{
private:
    Display &display;

public:
    explicit VoltagesListModal(Display &_display) : PresetsSelector(_display), display(_display) {}

    void show(const VoltageList &data, int devices_selector = 0, int option_selector = 0, int value_selector = 0)
    {
        PresetsSelector::show(devices_selector, option_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(25, 4, 76, 54);

        display.setColor(1);
        display.drawFrame(25, 4, 76, 54);

        display.setFont(u8g_font_5x7);
        display.drawText(33, 16, "VAL1");
        display.drawText(33, 29, "VAL2");
        display.drawText(33, 40, "VAL3");
        display.drawText(33, 52, "VAL4");
        display.setCursor(100, 11);
        
        display.setCursor(67, 16);
        display.print(String(data.getData()[0].getValue()));
        display.setCursor(67, 29);
        display.print(String(data.getData()[1].getValue()));
        display.setCursor(67, 40);
        display.print(String(data.getData()[2].getValue()));
        display.setCursor(67, 52);
        display.print(String(data.getData()[3].getValue()));

        display.drawFrame(28, ((value_selector * 12) + 7), 70, 12, 2);
    }
};
