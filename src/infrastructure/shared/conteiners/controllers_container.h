#pragma once
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <application/main/main_menu_controller.h>
#include <application/remote_devices/remote_devices_controller.h>
#include <application/device_configuration/device_configuration_controller.h>
#include <application/properties/properties_controller.h>
#include <application/settings/settings_controller.h>

class ControllersContainer
{
private:
    MainMenuController main_controller;
    RemoteDevicesController remote_devices_controller;
    ConfigureDevicesController configuration_controller;
    PropertiesController properties_controller;
    SettingsController settings_controller;

public:
    explicit ControllersContainer(InputsContainer &inputs, UIContainer &ui) : main_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_main_menu()),
                                                                              remote_devices_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_remote_devices_menu(),
                                                                                  ui.get_remote_devices_connected_modal(),
                                                                                  ui.get_remote_devices_disconnected_modal()),
                                                                              configuration_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_devices_configuration_menu(),
                                                                                  ui.get_values_configuration_menu(),
                                                                                  ui.get_configuration_modal()),
                                                                              properties_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_properties_menu()),
                                                                              settings_controller(
                                                                                  inputs.get_input_buttons(),
                                                                                  ui.get_settings_menu(),
                                                                                  ui.get_sound_modal(),
                                                                                  ui.get_clock_modal(),
                                                                                  ui.get_date_modal(),
                                                                                  ui.get_reset_modal(),
                                                                                  ui.get_physical_activation_modal(),
                                                                                  ui.get_remote_activation_modal(),
                                                                                  ui.get_device_boot_modal())
    {
    }

    MainMenuController &get_main_controller() { return main_controller; }
    RemoteDevicesController &get_remote_devices_controller() { return remote_devices_controller; }
    ConfigureDevicesController &get_configuration_controller() { return configuration_controller; }
    PropertiesController &get_properties_controller() { return properties_controller; }
};