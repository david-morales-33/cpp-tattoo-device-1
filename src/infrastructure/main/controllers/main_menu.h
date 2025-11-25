#pragma once
#include <infrastructure/display.h>
#include <core/main/views/letter_view.h>
#include <persistence/main/data.h>
#include <core/main/interfaces/main_menu_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/shared/data_transfer_objects/selector.h>

class MainMenu : public IMainMenuController
{

private:
    Display &display;
    LetterView view;
    Slider slider;
    LetterData options[7] = {{"DEVICES", 45}, {"SET", 55}, {"PROPERTIES", 38}, {"OPERATION", 38}, {"RESET", 50}, {"SETTINGS", 42}};
    Selector selector = Selector(6, 1);

public:
    explicit MainMenu(Display &disp) : display(disp), view(disp) {}

    void render(const DateTimeFormat &data) override
    {
        display.firstPage();
        do
        {
            view.show(slider, options[selector.getSelector()]);
        } while (display.nextPage());
    }

    void previous() override
    {
        selector.decrement();
        slider.left();
    }

    void next() override
    {
        selector.increment();
        slider.right();
    }

    const int getSelector() const override { return selector.getSelector(); }
};