#pragma once
#include <infrastructure/display.h>
#include <core/performance/views/performance_view.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_void.h>

class PerformanceMenu : public IMenuControllerVoid
{
private:
    Display &display;
    PerformanceView view;
    Selector selector;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit PerformanceMenu(Display &disp) : display(disp), view(disp) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show();
        } while (display.nextPage());
    }
    void previous() override { selector.decrement(); }
    void next() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};