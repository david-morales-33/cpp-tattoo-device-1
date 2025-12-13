#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/reset_modal.h>
#include <core/settings/data_transfer_objects/reset_selector.h>
#include <infrastructure/display.h>

class SettingsResetModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ResetModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    ResetSelector reset_selector;

public:
    explicit SettingsResetModal(
        Display &_display) : display(_display),
                             view(_display) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, reset_selector);
        } while (display.nextPage());
    }
    void left() override { reset_selector.switchReset(); }
    void right() override { reset_selector.switchReset(); }
    void enter() override { resolveEnter(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override { selectors = _selectors; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return reset_selector.getSelector(); }

private:
    void resolveEnter()
    {
        if (reset_selector.getReset() == ResetOptions::DEVICES)
        {
        }
        else
        {
        }
    }
};