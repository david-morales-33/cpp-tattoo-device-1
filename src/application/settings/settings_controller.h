#pragma once
#include <core/shared/interfaces/menu_controller_params.h>
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/sound_state.h>
#include <core/main/data_transfer_objects/slider.h>

class SettingsController
{
private:
    IInput &input;
    IMenuControllerParams<Slider> &main_menu;
    IMenuControllerParams<Slider> &date_time_menu;
    IPopupController<SoundState> &sound_modal;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit SettingsController(
        IInput &_input,
        IMenuControllerParams<Slider> &_main_menu,
        IMenuControllerParams<Slider> &_date_time_menu,
        IPopupController<SoundState> &_sound_modal) : input(_input),
                                                      main_menu(_main_menu),
                                                      date_time_menu(_date_time_menu),
                                                      sound_modal(_sound_modal)
    {
    }
    void execute()
    {
        if (main_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                main_menu.previous();
            if (input.isPressed(DOWN))
                main_menu.next();
            if (input.isPressed(ENTER))
                setSoundView();
            main_menu.render();
        }
        else if (date_time_menu.getState() == InterfaceState::VISIBLE & main_menu.getSelector() == 0)
        {
            if (input.isPressed(UP))
                date_time_menu.previous();
            if (input.isPressed(DOWN))
                date_time_menu.next();
            if (input.isPressed(BACK))
                setMainView();
            date_time_menu.render();
        }
        else if (sound_modal.getState() == InterfaceState::VISIBLE && main_menu.getSelector() == 1)
        {
            if (input.isPressed(LEFT))
                sound_modal.left();
            if (input.isPressed(RIGHT))
                sound_modal.right();
            if (input.isPressed(BACK))
                setMainView();
            if (input.isPressed(ENTER))
            {
                sound_modal.enter();
                setMainView();
            }
            sound_modal.render();
        }
    }

    InterfaceState getState() { return state; }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }

private:
    void setSoundView()
    {
        main_menu.hide();
        sound_modal.show();
    }
    void setMainView()
    {
        sound_modal.hide();
        date_time_menu.hide();
        main_menu.show();
    }
};