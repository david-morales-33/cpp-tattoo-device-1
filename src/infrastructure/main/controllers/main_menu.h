#pragma once
#include <infrastructure/display.h>
#include <core/main/views/letter_view.h>
#include <persistence/main/data.h>
#include <core/shared/interfaces/menu_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/main/interfaces/main_date_time_repository.h>

class MainMenu : public IMenuController
{

private:
    Display &display;
    IMainDateTimeRepository &repository;
    LetterView view;
    LetterData options[7] = {{"DEVICES", 45}, {"SET", 55}, {"PROPERTIES", 38}, {"OPERATION", 38}, {"RESET", 50}, {"SETTINGS", 42}};
    Slider slider;
    Selector selector = Selector(6, 1);

public:
    explicit MainMenu(Display &disp, IMainDateTimeRepository &_repository) : display(disp), view(disp), repository(_repository) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(slider, options[selector.getSelector()], repository.get());
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