#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/views/sound_modal.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/data_transfer_objects/sound_selector.h>
#include <infrastructure/display.h>

class SettingsSoundModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsSoundRepository &repository;
    SoundModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    SoundSelector sound_selector;

public:
    explicit SettingsSoundModal(
        Display &_display,
        ISettingsSoundRepository &_repository) : display(_display),
                                                 repository(_repository),
                                                 view(_display) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, sound_selector);
        } while (display.nextPage());
    }
    void left() override { sound_selector.switchSound(); }
    void right() override { sound_selector.switchSound(); }
    void enter() override { repository.update(sound_selector.getSound()); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        sound_selector.setSelector(repository.get());
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return sound_selector.getSelector(); }
};