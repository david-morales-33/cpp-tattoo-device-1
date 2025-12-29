#pragma once
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/main/persistence/main_date_time_repository_impl.h>
#include <infrastructure/remote_devices/persistence/remote_devices_repository_test_impl.h>
#include <infrastructure/settings/persistence/settings_sound_repository_impl.h>
#include <infrastructure/settings/persistence/settings_device_boot_repository_impl.h>
#include <infrastructure/settings/persistence/settings_device_activation_repository_impl.h>
#include <infrastructure/presets/persitence/presets_repository_impl.h>

class RepositoriesContainer
{
private:
    MainDateTimeRepositoryImpl main_repository;
    RemoteDevicesRepositoryTestImpl remote_devices_repository;
    SettingsSoundRepositoryImpl settings_sound_repository;
    SettingsDeviceBootRepositoryImpl settings_device_boot_repository;
    SettingsDeviceActivationRepositoryImpl settings_device_activation_repository;
    PresetsRepositoryImpl presets_repository;

public:
    explicit RepositoriesContainer(ProvidersContainerTest &providers_container) : main_repository(providers_container.get_main_provider()),
                                                                                  remote_devices_repository(providers_container.get_remote_devices_provider()),
                                                                                  settings_sound_repository(providers_container.get_settings_sound_provider()),
                                                                                  settings_device_boot_repository(providers_container.get_settings_device_boot_provider()),
                                                                                  settings_device_activation_repository(
                                                                                      providers_container.get_settings_remote_activation_provider(),
                                                                                      providers_container.get_settings_physical_activation_provider()),
                                                                                  presets_repository(
                                                                                      providers_container.get_presets_device_boot_provider(),
                                                                                      providers_container.get_presets_device_activation_provider(),
                                                                                      providers_container.get_presets_device_voltages_provider())

    {
    }
    MainDateTimeRepositoryImpl &get_main_repository() { return main_repository; }
    RemoteDevicesRepositoryTestImpl &get_remote_devices_repository() { return remote_devices_repository; }
    SettingsSoundRepositoryImpl &get_settings_sound_repository() { return settings_sound_repository; }
    SettingsDeviceBootRepositoryImpl &get_settings_device_boot_repository() { return settings_device_boot_repository; }
    SettingsDeviceActivationRepositoryImpl &get_settings_device_activation_repository() { return settings_device_activation_repository; }
    PresetsRepositoryImpl &get_presets_repository() { return presets_repository; }
};