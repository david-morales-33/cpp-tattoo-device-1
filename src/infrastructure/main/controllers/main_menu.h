#pragma once
#include <infrastructure/display.h>
#include <core/main/views/letter_view.h>
#include <core/main/views/main_view.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/main/data_transfer_objects/modal_data.h>
#include <core/shared/data_transfer_objects/counter.h>

class MainMenu : public IMenuControllerVoid
{

private:
    Display &display;
    IMainDateTimeRepository &repository;
    MainView main_view;
    LetterView modal_view;
    ModalData modal_data[6] = {{"DEVICES", 45}, {"SET", 55}, {"PROPERTIES", 38}, {"OPERATION", 38}, {"PERFORMANCE", 33}, {"SETTINGS", 42}};
    Slider slider;
    Selector selector;
    InterfaceState state = InterfaceState::VISIBLE;
    Counter counter;

public:
    explicit MainMenu(Display &disp, IMainDateTimeRepository &_repository) : display(disp),
                                                                             main_view(disp),
                                                                             modal_view(disp),
                                                                             repository(_repository),
                                                                             selector(6, 1),
                                                                             counter(15, 15) {}

    void render() override
    {
        if (!counter.isFinished())
        {
            counter.count();
            renderModalView();
        }
        else
            renderMainView();
    }

    void previous() override
    {
        counter.reset();
        selector.decrement();
        slider.left();
    }

    void next() override
    {
        counter.reset();
        selector.increment();
        slider.right();
    }

    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }

    const InterfaceState getState() const override { return state; }

    const int getSelector() const override { return selector.getSelector(); }

private:
    void renderModalView()
    {
        display.firstPage();
        do
        {
            modal_view.show(slider, modal_data[selector.getSelector()], repository.get());
        } while (display.nextPage());
    }

    void renderMainView()
    {
        display.firstPage();
        do
        {
            main_view.show(slider, repository.get());
        } while (display.nextPage());
    }
};