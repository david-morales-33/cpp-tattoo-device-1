#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/main/data_transfer_objects/time_format.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/clock_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/clock_selector.h>

class SettingsClockModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    IMainDateTimeRepository &repository;
    ClockModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    ClockSelector clock_selector;

public:
    explicit SettingsClockModal(
        Display &_display,
        IMainDateTimeRepository &_repository) : display(_display), repository(_repository), view(_display){}

    void render()
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, clock_selector);
        } while (display.nextPage());
    }
    void left() { clock_selector.left(); }
    void right() { clock_selector.right(); }
    void up() { clock_selector.increment(); }
    void down() { clock_selector.decrement(); }
    void enter() {}
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        clock_selector.setTime(5, 5, TimePeriod::PM);
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return clock_selector.getSelector(); }
};