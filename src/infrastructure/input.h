#pragma once
#include <Arduino.h>
#include "Pins.h"

class Input {
public:
    void begin() {
        pinMode(ENTER, INPUT_PULLUP);
        pinMode(BACK, INPUT_PULLUP);
        pinMode(UP, INPUT_PULLUP);
        pinMode(DOWN, INPUT_PULLUP);
        pinMode(RIGHT, INPUT_PULLUP);
        pinMode(LEFT, INPUT_PULLUP);
    }

    bool isPressed(int pin) {
        return digitalRead(pin) == LOW;
    }
};
