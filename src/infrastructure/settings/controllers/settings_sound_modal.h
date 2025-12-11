#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/views/sound_modal.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>

class SettingsSoundModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsSoundRepository &settings_repository;
    SoundModal view;
    SoundState sound_state;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    mutable int selector = 0;

public:
    explicit SettingsSoundModal(
        Display &_display,
        ISettingsSoundRepository &_settings_repository) : display(_display),
                                                          view(_display),
                                                          settings_repository(_settings_repository) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, sound_state);
        } while (display.nextPage());
    }
    void left() override { switchSoundState(); }
    void right() override { switchSoundState(); }
    void enter() override { settings_repository.update(sound_state); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        sound_state = settings_repository.get();
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return sound_state == SoundState::ON ? (selector = 1) : (selector = 0); }

private:
    void switchSoundState() { sound_state == SoundState::OFF ? sound_state = SoundState::ON : sound_state = SoundState::OFF; }
};