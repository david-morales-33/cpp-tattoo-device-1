#pragma once

#include <infrastructure/shared/interfaces/input.h>
#include <core/main/interfaces/main_menu_controller.h>
#include <core/main/interfaces/main_date_time_repository.h>

class MainMenuController
{
private:
    IInput &input;
    IMainMenuController &menu;
    IMainDateTimeRepository &repository;
    bool state = HIGH;

public:
    explicit MainMenuController(
        IInput &_input,
        IMainMenuController &_menu,
        IMainDateTimeRepository &_repository) : input(_input), menu(_menu), repository(_repository) {}

    void execute()
    {
        if (input.isPressed(LEFT))
            menu.previous();
        if (input.isPressed(RIGHT))
            menu.next();
        if (input.isPressed(ENTER))
            hide();
        if (state)
            menu.render(repository.get());
    }

    void hide() { state = LOW; }
    void show() { state = HIGH; }
    bool menuState() { return state; }
    int getSelector() { return menu.getSelector(); }
};