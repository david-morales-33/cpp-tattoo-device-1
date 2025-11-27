#include <Arduino.h>

#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>
#include <infrastructure/device_configuration/persistence/device_configuration_repository_impl.h>
#include <infrastructure/device_configuration/persistence/device_configuration_test_provider.h>
#include <application/device_configuration/device_configuration_controller.h>
#include <infrastructure/device_configuration/controllers/configure_values_menu.h>
#include <infrastructure/device_configuration/controllers/configure_devices_menu.h>
#include <infrastructure/device_configuration/controllers/configure_modal.h>

Display display;
InputImpl input;

DeviceConfigurationTestProvider provider;

DeviceConfigurationRepositoryImpl reposirory(provider);

ConfigureDevicesMenu devices_menu(display, reposirory);
ConfigureValuesMenu values_menu(display, reposirory);
ConfigureModal modal(display, reposirory);

ConfigureDevicesController controller(input, devices_menu, values_menu, modal);

void setup()
{
    display.begin();
    input.begin();
}
void loop()
{
    controller.execute();
}
