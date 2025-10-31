#include <Arduino.h>
#include <core/views/main_view.h>
#include <infrastructure/display.h>

Display display;
MainView mainView(display);

int ESTADO[8] = { -29, 3, 35, 67, 99, 131, 0, 1 };

void setup() {
    display.begin();
}
void loop() {
    
    mainView.show(ESTADO);
    delay(500);
}
