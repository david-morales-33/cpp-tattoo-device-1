#pragma once
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/main/controllers/main_menu.h>
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

    RemoteDevicesMenu remote_devices_menu;
    RemoteDevicesConnectedDeviceModal remote_devices_connected_modal;
    RemoteDevicesDisconnectedDevicesModal remote_devices_disconnected_modal;

    SettingsMenu settings_menu;
    SettingsSoundModal sound_modal;
    SettingsClockModal clock_modal;
    SettingsDateModal date_modal;
    SettingsResetModal reset_modal;
    SettingsDeviceBootModal device_boot_modal;
    SettingsPhysicalDeviceActivationModal physical_activation_modal;
    SettingsRemoteDeviceActivationModal remote_activation_modal;

public:
    explicit UIContainer(Display &display, RepositoriesContainer &repositories) : main_menu(display, repositories.get_main_repository()),
                                                                                  properties_menu(display, repositories.get_properties_repository()),
                                                                                  remote_devices_menu(display, repositories.get_remote_devices_repository()),
                                                                                  remote_devices_connected_modal(display, repositories.get_remote_devices_repository()),
                                                                                  remote_devices_disconnected_modal(display, repositories.get_remote_devices_repository()),
                                                                                  settings_menu(display),
                                                                                  sound_modal(display, repositories.get_settings_sound_repository()),
                                                                                  clock_modal(display, repositories.get_main_repository()),
                                                                                  date_modal(display, repositories.get_main_repository()),
                                                                                  reset_modal(display),
                                                                                  device_boot_modal(display, repositories.get_settings_device_boot_repository()),
                                                                                  remote_activation_modal(display, repositories.get_settings_device_activation_repository()),
                                                                                  physical_activation_modal(display, repositories.get_settings_device_activation_repository())

    {
    }

    MainMenu &get_main_menu() { return main_menu; }
    PropertiesMenu &get_properties_menu() { return properties_menu; }
    RemoteDevicesMenu &get_remote_devices_menu() { return remote_devices_menu; }
    RemoteDevicesConnectedDeviceModal &get_remote_devices_connected_modal() { return remote_devices_connected_modal; }
    RemoteDevicesDisconnectedDevicesModal &get_remote_devices_disconnected_modal() { return remote_devices_disconnected_modal; }
    SettingsMenu &get_settings_menu() { return settings_menu; }
    SettingsSoundModal &get_sound_modal() { return sound_modal; }
    SettingsClockModal &get_clock_modal() { return clock_modal; }
    SettingsDateModal &get_date_modal() { return date_modal; }
    SettingsResetModal &get_reset_modal() { return reset_modal; }
    SettingsDeviceBootModal &get_device_boot_modal() { return device_boot_modal; }
    SettingsPhysicalDeviceActivationModal &get_remote_activation_modal() { return physical_activation_modal; }
    SettingsRemoteDeviceActivationModal &get_physical_activation_modal() { return remote_activation_modal; }
};