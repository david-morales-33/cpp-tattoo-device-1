#pragma once
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/main/controllers/main_menu.h>
#include <infrastructure/device_configuration/controllers/devices_configuration_menu.h>
#include <infrastructure/device_configuration/controllers/values_configuration_menu.h>
#include <infrastructure/device_configuration/controllers/configuration_modal.h>
#include <infrastructure/properties/controllers/properties_menu.h>
#include <infrastructure/remote_devices/controllers/remote_devices_menu.h>
#include <infrastructure/remote_devices/controllers/remote_devices_connected_modal.h>
#include <infrastructure/remote_devices/controllers/remote_devices_disconnected_modal.h>
#include <infrastructure/settings/controllers/settings_menu.h>
#include <infrastructure/settings/controllers/settings_sound_modal.h>
#include <infrastructure/settings/controllers/settings_clock_modal.h>
#include <infrastructure/settings/controllers/settings_date_modal.h>
#include <infrastructure/settings/controllers/settings_device_boot_modal.h>
#include <infrastructure/settings/controllers/settings_reset_modal.h>
#include <infrastructure/settings/controllers/settings_physical_device_activation_modal.h>
#include <infrastructure/settings/controllers/settings_remote_device_activation_modal.h>

class UIContainer
{
private:
    MainMenu main_menu;

    PropertiesMenu properties_menu;

    DevicesConfigurationMenu devices_configuration_menu;
    ValuesConfigurationMenu values_configuration_menu;
    ConfigurationModal configuration_modal;

    RemoteDevicesMenu remote_devices_menu;
    RemoteDevicesConnectedDeviceModal remote_devices_connected_modal;
    RemoteDevicesDisconnectedDevicesModal remote_devices_disconnected_modal;

    SettingsMenu settings_menu;
    SettingsSoundModal sound_modal;
    SettingsClockModal clock_modal;
    SettingsDateModal date_modal;
    SettingsDeviceBootModal device_boot_modal;
    SettingsPhysicalDeviceActivationModal remote_activation_modal;
    SettingsRemoteDeviceActivationModal physical_activation_modal;

public:
    explicit UIContainer(Display &display, RepositoriesContainer &repositories) : main_menu(display, repositories.get_main_repository()),
                                                                                  properties_menu(display, repositories.get_properties_repository()),
                                                                                  devices_configuration_menu(display, repositories.get_devices_configuration()),
                                                                                  values_configuration_menu(display, repositories.get_devices_configuration()),
                                                                                  configuration_modal(display, repositories.get_devices_configuration()),
                                                                                  remote_devices_menu(display, repositories.get_remote_devices_repository()),
                                                                                  remote_devices_connected_modal(display, repositories.get_remote_devices_repository()),
                                                                                  remote_devices_disconnected_modal(display, repositories.get_remote_devices_repository()),
                                                                                  settings_menu(display, repositories.get_main_repository()),
                                                                                  sound_modal(display, repositories.get_settings_sound_repository()),
                                                                                  clock_modal(display, repositories.get_main_repository()),
                                                                                  date_modal(display, repositories.get_main_repository()),
                                                                                  device_boot_modal(display, repositories.get_settings_device_boot_repository()),
                                                                                  remote_activation_modal(display, repositories.get_settings_device_activation_repository()),
                                                                                  physical_activation_modal(display, repositories.get_settings_device_activation_repository())

    {
    }

    MainMenu &get_main_menu() { return main_menu; }
    PropertiesMenu &get_properties_menu() { return properties_menu; }
    DevicesConfigurationMenu &get_devices_configuration_menu() { return devices_configuration_menu; }
    ValuesConfigurationMenu &get_values_configuration_menu() { return values_configuration_menu; }
    ConfigurationModal &get_configuration_modal() { return configuration_modal; }
    RemoteDevicesMenu &get_remote_devices_menu() { return remote_devices_menu; }
    RemoteDevicesConnectedDeviceModal &get_remote_devices_connected_modal() { return remote_devices_connected_modal; }
    RemoteDevicesDisconnectedDevicesModal &get_remote_devices_disconnected_modal() { return remote_devices_disconnected_modal; }
    SettingsMenu &get_settings_menu() { return settings_menu; }
};