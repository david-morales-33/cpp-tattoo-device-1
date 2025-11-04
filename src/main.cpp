#include <Arduino.h>
#include <core/main/views/main_view.h>
#include <core/main/views/letter_view.h>
#include <infrastructure/display.h>
#include <core/operation/views/operation_view.h>
#include <persistence/main/data.h>
#include <core/properties/views/properties_view.h>
#include <core/reset/views/reset_view.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <core/device_configuration/views/device_configuration_selector.h>
#include <persistence/device_configuration/data.h>

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
PropertiesView propertiesView(display);
ResetView resetView(display);

int ESTADO[8] = {-29, 3, 35, 67, 99, 131, 0, 1};

void setup()
{
    display.begin();
}
void loop()
{
    display.firstPage();
    do
    {
        deviceConfSelector.show(1,3);
    } while (display.nextPage());

    delay(500);
}
