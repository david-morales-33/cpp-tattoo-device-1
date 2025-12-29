#pragma once
#include <infrastructure/main/persistence/main_date_time_provider_test.h>
#include <infrastructure/remote_devices/persistence/remote_devices_test_provider.h>
#include <infrastructure/settings/persistence/settings_sound_test_provider.h>
#include <infrastructure/settings/persistence/settings_device_boot_test_provider.h>
#include <infrastructure/settings/persistence/settings_physical_activation_test_provider.h>
#include <infrastructure/settings/persistence/settings_remote_activation_test_provider.h>
#include <infrastructure/presets/persitence/presets_activation_test_provider.h>
#include <infrastructure/presets/persitence/presets_boot_test_provider.h>
#include <infrastructure/presets/persitence/presets_voltages_test_provider.h>
#include <infrastructure/performance/persistence/performance_test_provider.h>
#include <infrastructure/performance/persistence/records_test_provider.h>

class ProvidersContainerTest
{
private:
    MainDateTimeProviderTest main_provider;
    RemoteDevicesTestProvider remote_devices_provider;
    SettingsSoundTestProvider settings_sound_provider;
    SettingsDeviceBootTestProvider settings_device_boot_provider;
    SettingsRemoteActivationTestProvider settings_remote_activation_provider;
    SettingsPhysicalActivationTestProvider settings_physical_activation_provider;
    PresetsBootTestProvider presets_device_boot_provider;
    PresetsActivationTestProvider presets_device_activation_provider;
    PresetsVoltageTestProvider presets_device_voltages_provider;
    PerformanceTestProvider performance_perovider;
    RecordTestProvider record_provider;

public:
    MainDateTimeProviderTest &get_main_provider() { return main_provider; }
    RemoteDevicesTestProvider &get_remote_devices_provider() { return remote_devices_provider; }
    SettingsSoundTestProvider &get_settings_sound_provider() { return settings_sound_provider; }
    SettingsDeviceBootTestProvider &get_settings_device_boot_provider() { return settings_device_boot_provider; }
    SettingsRemoteActivationTestProvider &get_settings_remote_activation_provider() { return settings_remote_activation_provider; }
    SettingsPhysicalActivationTestProvider &get_settings_physical_activation_provider() { return settings_physical_activation_provider; }
    PresetsBootTestProvider &get_presets_device_boot_provider() { return presets_device_boot_provider; }
    PresetsActivationTestProvider &get_presets_device_activation_provider() { return presets_device_activation_provider; }
    PresetsVoltageTestProvider &get_presets_device_voltages_provider() { return presets_device_voltages_provider; }
    PerformanceTestProvider &get_performance_perovider() { return performance_perovider; }
    RecordTestProvider &get_record_provider() { return record_provider; }
};
