#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_view.h>

class PresetsSelector : public PresetsView
{
private:
    Display &display;

public:
    explicit PresetsSelector(Display &_display) : PresetsView(_display), display(_display) {}

    void show(int device_selector = 0, int option_selector = 0)
    {
        PresetsView::show(device_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawFrame(65, ((16 * option_selector) + 1), 62, 14, 1);
    }
};