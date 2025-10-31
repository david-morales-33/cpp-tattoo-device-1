#include <Arduino.h>
#include <core/main/views/main_view.h>
#include <infrastructure/display.h>
#include <core/operation/views/operation_view.h>

Display display;
MainView mainView(display);
OperationView operationView(display);

int ESTADO[8] = {-29, 3, 35, 67, 99, 131, 0, 1};

void setup()
{
    display.begin();
}
void loop()
{

    operationView.show(0,0,1,0,0);
    //mainView.show(ESTADO);
    delay(500);
}
