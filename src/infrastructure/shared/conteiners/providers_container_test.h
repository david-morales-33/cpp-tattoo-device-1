#pragma once
#include <infrastructure/main/persistence/main_date_time_provider_test.h>
#include <infrastructure/device_configuration/persistence/device_configuration_test_provider.h>
#include <infrastructure/properties/persistence/properties_timer_test_provider.h>
#include <infrastructure/properties/persistence/properties_memory_provider.h>
#include <infrastructure/remote_devices/persistence/remote_devices_test_provider.h>

class ProvidersContainerTest
{
private:
    MainDateTimeProviderTest main_provider;
    DeviceConfigurationTestProvider device_configuration_provider;
    PropertiesMemoryProvider properties_memory_provider;
    PropertiesTimerTestProvider properties_timer_provider;
    RemoteDevicesTestProvider remote_devices_provider;

public:
    MainDateTimeProviderTest &get_main_provider() { return main_provider; }
    DeviceConfigurationTestProvider &get_device_configuration_provider() { return device_configuration_provider; }
    PropertiesMemoryProvider &get_properties_memory_provider() { return properties_memory_provider; }
    PropertiesTimerTestProvider &get_properties_timer_provider() { return properties_timer_provider; }
    RemoteDevicesTestProvider &get_remote_devices_provider() { return remote_devices_provider; }
};
