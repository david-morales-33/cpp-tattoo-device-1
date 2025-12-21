#pragma once
#include <infrastructure/display.h>
#include <core/presets/view/presets_view.h>

class PresetsSelector : public PresetsView
{
private:
    Display &display;

public:
    explicit PresetsSelector(Display &disp) : PresetsView(disp), display(disp) {}

    void show(int dev_selector = 0, int val_selector = 0)
    {
        PresetsView::show(dev_selector);
        display.setFontMode(1);
        display.setColor(0);
        display.drawFrame(65, ((16 * val_selector) + 1), 62, 14, 1); // selector 2//ini=2-->16++
    }
};