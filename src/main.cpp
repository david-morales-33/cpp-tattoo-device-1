#include <Arduino.h>
#include <infrastructure/display.h>

Display display;

void setup() {
    display.begin();    
}

void loop() {
    display.clear();
    display.drawText(0,10,u8g2_font_ncenB08_tr,"Hola, Test");
    display.render();
    delay(1000);
}
