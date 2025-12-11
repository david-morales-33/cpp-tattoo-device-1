#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/settings_sound_repository.h>
#include <core/settings/views/sound_modal.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/shared/data_transfer_objects/selector.h>

class SettingsSoundModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsSoundRepository &repository;
    SoundModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    Selector selector;
    SoundState sound_state_list[2] = {SoundState::OFF, SoundState::ON};

public:
    explicit SettingsSoundModal(
        Display &_display,
        ISettingsSoundRepository &_repository) : display(_display),
                                                 repository(_repository),
                                                 view(_display),
                                                 selector(2) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, sound_state_list[selector.getSelector()]);
        } while (display.nextPage());
    }
    void left() override { switchSelector(); }
    void right() override { switchSelector(); }
    void enter() override { repository.update(sound_state_list[selector.getSelector()]); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        repository.get() == SoundState::OFF ? selector.setSelector(0) : selector.setSelector(1);
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }

private:
    void switchSelector() { selector.getSelector() == 0 ? selector.setSelector(1) : selector.setSelector(0); }
};