#include <Arduino.h>
#include <core/main/views/main_view.h>
#include <core/main/views/letter_view.h>
#include <infrastructure/display.h>
#include <core/operation/views/operation_view.h>
#include <persistence/main/data.h>
#include <core/properties/views/properties_view.h>
#include <core/reset/views/reset_view.h>
#include <core/reset/views/reset_confirmation_view.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <core/device_configuration/views/device_configuration_selector.h>
#include <core/device_configuration/views/device_configuration_window.h>
#include <persistence/device_configuration/data.h>
#include <core/settings/views/settings_view.h>
#include <core/settings/views/sound_view.h>
#include <core/settings/views/settings_options_view.h>
#include <core/linked_devices/views/linked_devices_view.h>

Display display;
MainView mainView(display);

OperationView operationView(display);

LetterView letterView(display);
LetterData data[7] = {
    {"DEVICES", 45},
    {"SET", 55},
    {"PROPERTIES", 38},
    {"OPERATION", 38},
    {"RESET", 38},
    {"SETTINGS", 38},
};

VoltageData voltages = {{{10.5, 3.4, 7.7, 9.5},
                         {2.3, 5.6, 7.9, 8.2}}};

DeviceConfigurationView deviceConfView(display, voltages);
DeviceConfigurationSelector deviceConfSelector(display, voltages);
DeviceConfigurationWindow deviceConfigWindow(display, voltages);
SettingsView settingView(display, "SOUND");

PropertiesView propertiesView(display);
ResetView resetView(display);
ResetConfirmationView resetConfirmView(display);
SoundView soundView(display);
SettingsOptionsView optionsView(display);
LinkedDevicesView likedView(display);

// int ESTADO[8] = {-29, 3, 35, 67, 99, 131, 0, 1};
SliderData slider;

void setup()
{
    display.begin();
}
void loop()
{
    display.firstPage();
    do
    {
        likedView.show();
    } while (display.nextPage());

    delay(500);
}
