#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/views/settings_sound_view.h>
#include <infrastructure/display.h>

class SettingsSoundModal : public IPopupController<Slider>
{
private:
    Display &display;
    IMainDateTimeRepository &main_repository;
    ISettingsSoundRepository &settings_repository;
    SettingSoundView view;
    Selector selector;
    SoundState sound_state;
    InterfaceState state = InterfaceState::HIDDEN;
    Slider slider;
    DateTimeFormat date_time;

public:
    explicit SettingsSoundModal(
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
            view.show(slider, date_time, sound_state);
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
    const int &getSelector() const override { return selector.getSelector(); }

private:
    void switchSoundState()
    {
        if (sound_state == SoundState::OFF)
        {
            sound_state = SoundState::ON;
            selector.setSelector(1);
        }
        else
        {
            sound_state = SoundState::OFF;
            selector.setSelector(0);
        }
    }
};