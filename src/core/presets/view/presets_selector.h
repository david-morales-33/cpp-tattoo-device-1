#pragma once
#include <infrastructure/display.h>
#include <core/presets/view/presets_view.h>

class PresetsSelector : public PresetsView
{
private:
    Display &display;

public:
    explicit PresetsSelector(Display &disp) : PresetsView(disp), display(disp) {}

    void show(int device_selector = 0, int option_selector = 0)
    {
        PresetsView::show(device_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawFrame(65, ((16 * option_selector) + 1), 62, 14, 1);
    }
};