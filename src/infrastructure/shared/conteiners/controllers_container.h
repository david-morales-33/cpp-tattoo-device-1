#pragma once
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <application/main/main_menu_controller.h>
#include <application/remote_devices/remote_devices_controller.h>
#include <application/settings/settings_controller.h>
#include <application/presets/presets_controllers.h>
#include <application/performance/performance_controller.h>
#include <application/operation/operation_controller.h>
#include <application/shared/controller.h>

class ControllersContainer
{
private:
    MainMenuController main_controller;
    SettingsController settings_controller;
    PresetsController presets_controller;
    PerformanceController performance_controller;
    OperationController operation_controller;

    IController *controllers[4];

public:
    explicit ControllersContainer(InputsContainer &inputs, UIContainer &ui) : main_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_main_menu()),
                                                                              settings_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_settings_menu(),
                                                                                  ui.get_sound_modal(),
                                                                                  ui.get_clock_modal(),
                                                                                  ui.get_date_modal(),
                                                                                  ui.get_reset_modal(),
                                                                                  ui.get_physical_activation_modal(),
                                                                                  ui.get_remote_activation_modal()),
                                                                              presets_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_presets_menu(),
                                                                                  ui.get_presets_option_selector(),
                                                                                  ui.get_presets_voltages_list_modal(),
                                                                                  ui.get_presets_voltage_selector_modal(),
                                                                                  ui.get_presets_device_boot_modal(),
                                                                                  ui.get_presets_device_activation_modal(),
                                                                                  ui.get_presets_remote_devices_modal()),
                                                                              performance_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_performance_menu(),
                                                                                  ui.get_records_modal())
    {
        controllers[0] = &presets_controller;
        controllers[1] = &operation_controller;
        controllers[2] = &performance_controller;
        controllers[3] = &settings_controller;
    }

    MainMenuController &get_main_controller() { return main_controller; }
    IController *const *get_controllers() const { return controllers; }
};