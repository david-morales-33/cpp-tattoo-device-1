#include <Arduino.h>
#include <core/main/views/main_view.h>
#include <core/main/views/letter_view.h>
#include <infrastructure/display.h>
#include <core/operation/views/operation_view.h>
#include <persistence/main/data.h>
#include <core/properties/views/properties_view.h>

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

PropertiesView propertiesView(display);

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
        propertiesView.show();
    } while (display.nextPage());

    delay(500);
}
