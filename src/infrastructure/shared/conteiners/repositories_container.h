#pragma once
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/main/persistence/main_date_time_repository_impl.h>
#include <infrastructure/remote_devices/persistence/remote_devices_repository_test_impl.h>
#include <infrastructure/properties/persistence/properties_timer_repository.h>
#include <infrastructure/device_configuration/persistence/device_configuration_repository_impl.h>
#include <infrastructure/settings/persistence/settings_sound_repository_impl.h>
#include <infrastructure/settings/persistence/settings_device_boot_repository_impl.h>
#include <infrastructure/settings/persistence/settings_device_activation_repository_impl.h>

class RepositoriesContainer
{
private:
    MainDateTimeRepositoryImpl main_repository;
    RemoteDevicesRepositoryTestImpl remote_devices_repository;
    PropertiesTimerRepository properties_repository;
    DeviceConfigurationRepositoryImpl devices_configuration;
    SettingsSoundRepositoryImpl settings_sound_repository;
    SettingsDeviceBootTestProvider settings_device_boot_repository;
    SettingsDeviceActivationRepositoryImpl settings_device_activation_repository;

public:
    explicit RepositoriesContainer(ProvidersContainerTest &providers_container) : main_repository(providers_container.get_main_provider()),
                                                                                  remote_devices_repository(providers_container.get_remote_devices_provider()),
                                                                                  properties_repository(
                                                                                      providers_container.get_properties_memory_provider(),
                                                                                      providers_container.get_properties_timer_provider()),
                                                                                  devices_configuration(providers_container.get_device_configuration_provider()),
                                                                                  settings_sound_repository(providers_container.get_settings_sound_provider()),
                                                                                  settings_device_boot_repository(providers_container.get_settings_device_boot_provider()),
                                                                                  settings_device_activation_repository(
                                                                                      providers_container.get_settings_remote_activation_provider(),
                                                                                      providers_container.get_settings_physical_activation_provider())

    {
    }
    MainDateTimeRepositoryImpl &get_main_repository() { return main_repository; }
    RemoteDevicesRepositoryTestImpl &get_remote_devices_repository() { return remote_devices_repository; }
    PropertiesTimerRepository &get_properties_repository() { return properties_repository; }
    DeviceConfigurationRepositoryImpl &get_devices_configuration() { return devices_configuration; }
    SettingsSoundRepositoryImpl &get_settings_sound_repository() { return settings_sound_repository; }
    SettingsDeviceBootTestProvider &get_settings_device_boot_repository() { return settings_device_boot_repository; }
    SettingsDeviceActivationRepositoryImpl &get_settings_device_activation_repository() { return settings_device_activation_repository; }
};