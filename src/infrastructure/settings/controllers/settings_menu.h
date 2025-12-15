#pragma once
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/views/settings_view.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <infrastructure/display.h>

class SettingsMenu : public IMenuControllerParams<int>
{
private:
    Display &display;
    SettingsView view;
    Selector side_selector;
    Selector value_selector;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit SettingsMenu(Display &_display) : display(_display),
                                               view(_display),
                                               side_selector(2),
                                               value_selector(4)
    {
    }

    void load(const int &value_selector) override { side_selector.setSelector(value_selector); }

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(side_selector.getSelector(), value_selector.getSelector());
        } while (display.nextPage());
    }
    void next() override { value_selector.increment(); }
    void previous() override { value_selector.decrement(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return value_selector.getSelector(); }
};