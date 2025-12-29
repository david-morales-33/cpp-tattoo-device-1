#pragma once
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <application/main/main_menu_controller.h>
#include <application/remote_devices/remote_devices_controller.h>
#include <application/settings/settings_controller.h>
#include <application/presets/presets_controllers.h>

class ControllersContainer
{
private:
    MainMenuController main_controller;
    RemoteDevicesController remote_devices_controller;
    SettingsController settings_controller;
    PresetsController presets_controller;

public:
    explicit ControllersContainer(InputsContainer &inputs, UIContainer &ui) : main_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_main_menu()),
                                                                              remote_devices_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_remote_devices_menu(),
                                                                                  ui.get_remote_devices_connected_modal(),
                                                                                  ui.get_remote_devices_disconnected_modal()),
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
                                                                                  ui.get_presets_device_activation_modal())
    {
    }

    MainMenuController &get_main_controller() { return main_controller; }
    RemoteDevicesController &get_remote_devices_controller() { return remote_devices_controller; }
    SettingsController &get_settings_controller() { return settings_controller; }
    PresetsController &get_presets_controller() { return presets_controller; }
};