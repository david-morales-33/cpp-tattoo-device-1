#pragma once
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/main/persistence/main_date_time_repository_impl.h>
#include <infrastructure/remote_devices/persistence/remote_devices_repository_test_impl.h>
#include <infrastructure/properties/persistence/properties_timer_repository.h>
#include <infrastructure/device_configuration/persistence/device_configuration_repository_impl.h>

class RepositoriesContainer
{
private:
    MainDateTimeRepositoryImpl main_repository;
    RemoteDevicesRepositoryTestImpl remote_devices_repository;
    PropertiesTimerRepository properties_repository;
    DeviceConfigurationRepositoryImpl devices_configuration;

public:
    explicit RepositoriesContainer(ProvidersContainerTest &providers_container) : main_repository(providers_container.get_main_provider()),
                                                                                   remote_devices_repository(providers_container.get_remote_devices_provider()),
                                                                                   properties_repository(
                                                                                       providers_container.get_properties_memory_provider(),
                                                                                       providers_container.get_properties_timer_provider()),
                                                                                   devices_configuration(providers_container.get_device_configuration_provider())

    {
    }
    MainDateTimeRepositoryImpl &get_main_repository() { return main_repository; }
    RemoteDevicesRepositoryTestImpl &get_remote_devices_repository() { return remote_devices_repository; }
    PropertiesTimerRepository &get_properties_repository() { return properties_repository; }
    DeviceConfigurationRepositoryImpl &get_devices_configuration() { return devices_configuration; }
};