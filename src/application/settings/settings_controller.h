#pragma once
#include <core/shared/interfaces/menu_controller_void.h>
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/interface_state.h>

class SettingsController
{
private:
    IInput &input;
    IMenuControllerVoid &main_menu;
    IMenuControllerVoid &date_time_menu;
    IMenuControllerVoid &sound_menu;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit SettingsController(
        IInput &_input,
        IMenuControllerVoid &_main_menu,
        IMenuControllerVoid &_date_time_menu,
        IMenuControllerVoid &_sound_menu) : input(_input),
                                            main_menu(_main_menu),
                                            date_time_menu(_date_time_menu),
                                            sound_menu(_sound_menu)
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
        else if (sound_menu.getState() == InterfaceState::VISIBLE && main_menu.getSelector() == 1)
        {
            if (input.isPressed(LEFT))
                sound_menu.next();
            if (input.isPressed(RIGHT))
                sound_menu.next();
            if (input.isPressed(BACK))
                setMainView();
            sound_menu.render();
        }
    }

    InterfaceState getState() { return state; }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }

private:
    void setSoundView()
    {
        main_menu.hide();
        sound_menu.show();
    }
    void setMainView()
    {
        sound_menu.hide();
        main_menu.show();
    }
};