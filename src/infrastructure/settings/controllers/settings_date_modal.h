#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/main/data_transfer_objects/time_format.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/date_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/date_selector.h>

class SettingsDateModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    IMainDateTimeRepository &repository;
    DateModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    DateSelector date_selector;

public:
    explicit SettingsDateModal(
        Display &_display,
        IMainDateTimeRepository &_repository) : display(_display), repository(_repository), view(_display) {}

    void render()
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, date_selector);
        } while (display.nextPage());
    }
    void left() { date_selector.left(); }
    void right() { date_selector.right(); }
    void up() { date_selector.increment(); }
    void down() { date_selector.decrement(); }
    void enter() {}
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        date_selector.setDate(1, 1, 2025);
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return date_selector.getSelector(); }
};