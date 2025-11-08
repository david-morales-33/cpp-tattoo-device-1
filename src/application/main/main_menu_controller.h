#pragma once
#include <application/main/main_menu.h>
#include <infrastructure/input.h>
#include <infrastructure/display.h>

class MainMenuConytroller
{
private:
    Display &display;
    MainMenu menu;
    Input input;
    bool state = HIGH;

public:
    explicit MainMenuConytroller(Display &disp) : display(disp), menu(disp) {}

    void begin() { input.begin(); }

    void execute()
    {
        if (input.isPressed(LEFT))
            menu.left();
        if (input.isPressed(RIGHT))
            menu.right();
        if (input.isPressed(ENTER))
            hide();
        if (state)
            menu.render();
    }

    void hide() { state = LOW; }
    void show() { state = HIGH; }
    bool menuState() { return state; }
    int getSelector() { return menu.getSelector(); }
};