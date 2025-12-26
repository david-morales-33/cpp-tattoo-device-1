#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/presets_view.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_void.h>

class PresetsMenu : public IMenuControllerVoid
{
private:
    Display &display;
    PresetsView view;
    Selector selector;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit PresetsMenu(Display &disp) : display(disp), view(disp), selector(2) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selector.getSelector());
        } while (display.nextPage());
    }
    void previous() override { selector.decrement(); }
    void next() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};