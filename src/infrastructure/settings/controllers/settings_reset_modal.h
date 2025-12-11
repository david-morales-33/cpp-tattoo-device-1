#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/reset_modal.h>
#include <core/settings/interfaces/reset_options.h>
#include <infrastructure/display.h>

class SettingsResetModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ResetModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    ResetOptions option = ResetOptions::ALL;
    mutable int selector = 0;

public:
    explicit SettingsResetModal(
        Display &_display) : display(_display),
                             view(_display) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, option);
        } while (display.nextPage());
    }
    void left() override { switchResetOption(); }
    void right() override { switchResetOption(); }
    void enter() override { resolveEnter(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override { selectors = _selectors; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector; }

private:
    void switchResetOption() { option == ResetOptions::ALL ? option = ResetOptions::DEVICES : option = ResetOptions::ALL; }
    void resolveEnter()
    {
        if (option == ResetOptions::DEVICES)
        {
        }
        else
        {
        }
    }
};