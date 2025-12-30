#pragma once
#include <infrastructure/shared/conteiners/controllers_container.h>

class App
{
private:
    ControllersContainer &controllers;

public:
    explicit App(ControllersContainer &_controllers) : controllers(_controllers) {}

    void begin() {}

    void run()
    {
        int option = controllers.get_main_controller().getSelector();

        if (resolve_state_controller(option))
        {
            controllers.get_controllers()[option]->execute();
            end_process(option);
        }
        else
        {
            controllers.get_main_controller().execute();
            if (controllers.get_main_controller().getState() == InterfaceState::HIDDEN)
                entry_event(option);
        }
    }

private:
    void entry_event(int option) { controllers.get_controllers()[option]->show(); }

    bool resolve_state_controller(int option)
    {
        return controllers.get_controllers()[option]->getState() == InterfaceState::VISIBLE;
    }

    void end_process(int option)
    {
        if (!resolve_state_controller(option))
            controllers.get_main_controller().show();
    }
};