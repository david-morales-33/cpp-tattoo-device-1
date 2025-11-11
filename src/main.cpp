#include <Arduino.h>
#include <infrastructure/display.h>
#include <application/main/main_menu_controller.h>
#include <application/configure_devices/configure_devices_menu.h>
#include <application/configure_devices/configure_devices_controller.h>
#include <application/link_devices/link_devices_controller.h>
#include <core/linked_devices/views/available_devices_window.h>
/*
#include <core/main/views/main_view.h>
#include <core/main/views/letter_view.h>
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
#include <core/linked_devices/views/linked_devices_window.h>
*/
Display display;
// MainMenuConytroller menu(display);
VoltageData voltages = {{{10.5, 3.4, 7.7, 9.5},
                         {2.3, 5.6, 7.9, 8.2}}};

DevicesData dev1("cs.a.sd.s.", "machine", "MACH_1");
DevicesData dev2("cs.a.wew.s.", "machine", "MACH_2");
DevicesData dev4("cs.a.sa.s.", "machine", "MACH_3");
DevicesData dev5("cs.a.sr.xp.", "machine", "MACH_4");
DevicesData dev6("cs.a.zd.xp.", "machine", "MACH_5");

DevicesListData devices({dev1, dev2}, {dev4});
LinkedDevicesData linked({dev6}, {dev5});

LinkDevicesController menu(display, devices);

AvailableDevicesWindow window(display, devices, linked);

// ConfigureDevicesMenu menu
/*
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


DeviceConfigurationView deviceConfView(display, voltages);
DeviceConfigurationSelector deviceConfSelector(display, voltages);
DeviceConfigurationWindow deviceConfigWindow(display, voltages);
SettingsView settingView(display, "SOUND");

PropertiesView propertiesView(display);
ResetView resetView(display);
ResetConfirmationView resetConfirmView(display);
SoundView soundView(display);
SettingsOptionsView optionsView(display);
LinkedDevicesView linkedView(display);

LinkedDevicesWindow LinkedWind(display, "PAIR DEVICE?");
// LinkedDevicesWindow LinkedWind(display, "REMOVE DEVICE?");

// int ESTADO[8] = {-29, 3, 35, 67, 99, 131, 0, 1};
SliderData slider;
*/
void setup()
{

    display.begin();
    menu.begin();
}
void loop()
{

    display.firstPage();
    do
    {
        window.show();
    } while (display.nextPage());
}
