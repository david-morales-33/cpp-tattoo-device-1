#pragma once
#include <core/properties/views/properties_view.h>
#include <core/properties/interfaces/properties_timer_repository.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/interface_state.h>
#include <infrastructure/display.h>

class PropertiesMenu : public IMenuControllerVoid
{
private:
    Display &display;
    IPropertiesTimerRepository &repository;
    PropertiesView view;
    Selector selector;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit PropertiesMenu(
        Display &_display,
        IPropertiesTimerRepository &_repository) : display(_display),
                                                   view(_display),
                                                   repository(_repository),
                                                   selector(2) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selector.getSelector());
        } while (display.nextPage());
    }
    void next() override { selector.increment(); }
    void previous() override { selector.decrement(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};
