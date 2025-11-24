#pragma once
#include <Arduino.h>
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>

class InputImpl: IInput
{
private:
    static const uint8_t BUTTON_COUNT = 6;

    const int pins[BUTTON_COUNT] = {ENTER, BACK, UP, DOWN, RIGHT, LEFT};
    bool states[BUTTON_COUNT] = {LOW};
    bool lastStableStates[BUTTON_COUNT] = {LOW};
    unsigned long lastChangeTimes[BUTTON_COUNT] = {0};
    const unsigned long debounceDelay = 50; // milisegundos

public:
    void begin()
    {
        for (uint8_t i = 0; i < BUTTON_COUNT; i++)
        {
            pinMode(pins[i], INPUT);
        }
    }

    bool isPressed(int pin) override
    {
        uint8_t index = getIndex(pin);
        if (index == 255) return false; // pin no encontrado

        bool reading = digitalRead(pin);
        unsigned long now = millis();

        // Si cambió el estado actual respecto al último estable
        if (reading != states[index])
        {
            states[index] = reading;
            lastChangeTimes[index] = now;
        }

        // Si ha pasado el tiempo de rebote y el estado cambió
        if ((now - lastChangeTimes[index]) > debounceDelay)
        {
            if (lastStableStates[index] != states[index])
            {
                lastStableStates[index] = states[index];

                // Solo consideramos pulsación si está en HIGH
                if (states[index] == HIGH)
                    return true;
            }
        }

        return false;
    }

private:
    uint8_t getIndex(int pin)
    {
        for (uint8_t i = 0; i < BUTTON_COUNT; i++)
        {
            if (pins[i] == pin) return i;
        }
        return 255;
    }
};
