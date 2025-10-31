#pragma once

#include <infrastructure/display.h>
#include <persistence/main/data.h>
#include <infrastructure/icons_size.h>
#include <core/main/icons/bluethooth.h>
#include <core/main/icons/device.h>
#include <core/main/icons/properties.h>
#include <core/main/icons/operation.h>
#include <core/main/icons/reset.h>
#include <core/main/icons/settings.h>

class MainView
{
private:
    Display &display; // referencia para no copiar el objeto

public:
    explicit MainView(Display &disp) : display(disp) {}

    void show(int positions[8])
    {
        display.clear();

        // --- Dibujo de íconos principales ---
        display.setColor(1);
        display.drawBitmap(positions[0], 35, WIDTH, HEIGHT, BLUETOOTH_BITS);
        display.drawBitmap(positions[1], 35, WIDTH, HEIGHT, DEVICE_BITS);
        display.drawBitmap(positions[2], 35, WIDTH, HEIGHT, PROPERTIES_BITS);
        display.drawBitmap(positions[3], 35, WIDTH, HEIGHT, OPERATION_BITS);
        display.drawBitmap(positions[4], 35, WIDTH, HEIGHT, RESET_BITS);
        display.drawBitmap(positions[5], 35, WIDTH, HEIGHT, SETTINGS_BITS);
        
        // --- Recuadros principales ---
        display.drawFrame(2, 34, 28, 28, 3);
        display.drawFrame(34, 34, 28, 28, 3);
        display.drawFrame(66, 34, 28, 28, 3);
        display.drawFrame(98, 34, 28, 28, 3);
        
        display.drawFrame(0, 0, 63, 31, 1);
        display.drawFrame(65, 0, 63, 31, 1);
        display.drawBox(1, 1, 61, 30);
        
        // --- Fecha y hora ---
        display.setColor(0);
        display.drawText(2, 27, "09/04/2021", u8g2_font_6x10_tf, 0);
        display.drawText(2, 16, "17:37", u8g2_font_luRS14_tf, 0);
        
        // --- Temperatura y día ---
        display.setColor(1);
        display.drawText(86, 16, "23c", u8g2_font_luRS14_tf);
        display.drawText(80, 27, "Monday", u8g2_font_6x10_tf);

        // --- Ícono de clima ---
        display.drawGlyph(68, 18, u8g2_font_open_iconic_all_2x_t, 0x0103);

        // --- Selector de íconos ---
        display.highlightBox((positions[6] * 32), 32, 32, 32);

        display.render();
    }
};
