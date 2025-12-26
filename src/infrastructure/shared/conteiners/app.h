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

        if (option == 0 && resolve_state_controller(option))
        {
            controllers.get_remote_devices_controller().execute();
            end_process(option);
        }

        else if (option == 1 && resolve_state_controller(option))
        {
            controllers.get_presets_controller().execute();
            end_process(option);
        }

        else if (option == 2 && resolve_state_controller(option))
        {
            controllers.get_properties_controller().execute();
            end_process(option);
        }

        else if (option == 3 && false)
        {
        }
        else if (option == 4 && false)
        {
        }
        else if (option == 5 && resolve_state_controller(option))
        {
            controllers.get_settings_controller().execute();
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
    void exit_event() { controllers.get_main_controller().show(); }

    void entry_event(int option)
    {
        if (option == 0)
            controllers.get_remote_devices_controller().show();

        else if (option == 1)
            controllers.get_presets_controller().show();

        else if (option == 2)
            controllers.get_properties_controller().show();

        else if (option == 5)
            controllers.get_settings_controller().show();
    }

    bool resolve_state_controller(int option)
    {
        switch (option)
        {
        case 0:
            return controllers.get_remote_devices_controller().getState() == InterfaceState::VISIBLE;
            break;
        case 1:
            return controllers.get_presets_controller().getState() == InterfaceState::VISIBLE;
            break;
        case 2:
            return controllers.get_properties_controller().getState() == InterfaceState::VISIBLE;
            break;
        case 3:
            return false;
            break;
        case 4:
            return false;
            break;
        case 5:
            return controllers.get_settings_controller().getState() == InterfaceState::VISIBLE;
            break;
        default:
            return false;
            break;
        }
    }

    void end_process(int option)
    {
        if (!resolve_state_controller(option))
            exit_event();
    }
};