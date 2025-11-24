#pragma once
#include <infrastructure/display.h>
#include <core/main/views/letter_view.h>
#include <persistence/main/data.h>
#include <core/main/interfaces/main_menu_controller.h>

class MainMenu : public IMainMenuController
{

private:
    Display &display;
    LetterView view;
    SliderData slider;
    LetterData options[7] = {{"DEVICES", 45}, {"SET", 55}, {"PROPERTIES", 38}, {"OPERATION", 38}, {"RESET", 50}, {"SETTINGS", 42}};
    int selector = 1;

public:
    explicit MainMenu(Display &disp) : display(disp), view(disp) {}

    void render(DateTimeFormat data) override
    {
        display.firstPage();
        do
        {
            view.show(slider, options[selector]);
        } while (display.nextPage());
    }

    void left() override
    {
        if (selector > 0)
            selector = selector - 1;

        if (slider.icons_selector > 0)
            slider.icons_selector = slider.icons_selector - 1;
        else if (slider.icons_selector == 0 && slider.view_selector > 0)
        {
            slider.view_selector = slider.view_selector - 1;
            for (int i = 0; i < 6; i++)
                slider.icons_slider[i] = slider.icons_slider[i] + 32;
        }
    }

    void right() override
    {
        if (selector < 5)
            selector = selector + 1;

        if (slider.icons_selector < 3)
            slider.icons_selector = slider.icons_selector + 1;
        else if (slider.icons_selector == 3 && slider.view_selector < 2)
        {
            slider.view_selector = slider.view_selector + 1;
            for (int i = 0; i < 6; i++)
                slider.icons_slider[i] = slider.icons_slider[i] - 32;
        }
    }

    const int getSelector() const override { return selector; }
};