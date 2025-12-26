#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_selector.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_params.h>

class PresetsOptionsSelectorMenu : public IMenuControllerParams<int>
{
private:
    Display &display;
    PresetsSelector view;
    Selector options_selector;
    InterfaceState state = InterfaceState::HIDDEN;
    int devices_selector = 0;

public:
    explicit PresetsOptionsSelectorMenu(Display &_display) : view(_display), display(_display), options_selector(3) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(devices_selector, options_selector.getSelector());
        } while (display.nextPage());
    }
    void load(const int &dev_selector = 0) override { devices_selector = dev_selector; }
    void previous() override { options_selector.decrement(); }
    void next() override { options_selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return options_selector.getSelector(); }
};