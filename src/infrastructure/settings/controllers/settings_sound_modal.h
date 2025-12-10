#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/views/settings_sound_modal.h>
#include <infrastructure/display.h>

class SettingsSoundModalImpl : public IPopupController<Slider>
{
private:
    Display &display;
    IMainDateTimeRepository &main_repository;
    ISettingsSoundRepository &settings_repository;
    SettingsSoundModal view;
    SoundState sound_state;
    InterfaceState state = InterfaceState::HIDDEN;
    Slider slider;
    DateTimeFormat date_time;
    mutable int selector = 0;

public:
    explicit SettingsSoundModalImpl(
        Display &_display,
        IMainDateTimeRepository &_main_repository,
        ISettingsSoundRepository &_settings_repository) : display(_display),
                                                          view(_display),
                                                          main_repository(_main_repository),
                                                          settings_repository(_settings_repository) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show();
        } while (display.nextPage());
    }
    void left() override { switchSoundState(); }
    void right() override { switchSoundState(); }
    void enter() override { settings_repository.update(sound_state); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const Slider &_slider) override
    {
        slider = _slider;
        sound_state = settings_repository.get();
        date_time = main_repository.get();
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return sound_state == SoundState::ON ? (selector = 1) : (selector = 0); }

private:
    void switchSoundState() { sound_state == SoundState::OFF ? sound_state = SoundState::ON : sound_state = SoundState::OFF; }
};