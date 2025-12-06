#pragma once
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/views/settings_view.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <infrastructure/display.h>

class SettingsMenu : public IMenuControllerParams<Slider>
{
private:
    Display &display;
    IMainDateTimeRepository &repository;
    SettingsView view;
    Selector selector;
    Slider slider;
    DateTimeFormat date_time;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit SettingsMenu(
        Display &_display,
        IMainDateTimeRepository &_repository) : display(_display),
                                                view(_display),
                                                repository(_repository),
                                                selector(2) {}

    void load(const Slider &_slider) override
    {
        slider = _slider;
        date_time = repository.get();
    }

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(slider, date_time, selector.getSelector());
        } while (display.nextPage());
    }
    void next() override { selector.increment(); }
    void previous() override { selector.decrement(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};