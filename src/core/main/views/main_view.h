#pragma once

#include <infrastructure/display.h>
#include <core/main/data_transfer_objects/slider.h>
#include <infrastructure/icons_size.h>
#include <core/main/icons/bluethooth.h>
#include <core/main/icons/device.h>
#include <core/main/icons/properties.h>
#include <core/main/icons/operation.h>
#include <core/main/icons/reset.h>
#include <core/main/icons/settings.h>
#include <core/main/data_transfer_objects/date_time_format.h>

class MainView
{
private:
    Display &display; // referencia para no copiar el objeto

public:
    explicit MainView(Display &disp) : display(disp) {}

    void show(const Slider &slider, const DateTimeFormat &data)
    {
        
        // --- Dibujo de íconos principales ---
        display.setColor(1);
        display.drawBitmap(slider.getIconsSlider()[0], 35, WIDTH, HEIGHT, BLUETOOTH_BITS);
        display.drawBitmap(slider.getIconsSlider()[1], 35, WIDTH, HEIGHT, DEVICE_BITS);
        display.drawBitmap(slider.getIconsSlider()[2], 35, WIDTH, HEIGHT, PROPERTIES_BITS);
        display.drawBitmap(slider.getIconsSlider()[3], 35, WIDTH, HEIGHT, OPERATION_BITS);
        display.drawBitmap(slider.getIconsSlider()[4], 35, WIDTH, HEIGHT, RESET_BITS);
        display.drawBitmap(slider.getIconsSlider()[5], 35, WIDTH, HEIGHT, SETTINGS_BITS);

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
        display.setFont(u8g2_font_6x10_tf);
        display.drawText(2, 27, data.getDate().getDate().c_str());
        display.setFont(u8g2_font_luRS14_tf);
        display.drawText(2, 16, data.getTime().getTime().c_str());

        // --- Temperatura y día ---
        display.setColor(1);
        display.setFont(u8g2_font_luRS14_tf);
        display.drawText(86, 16, "23c");
        display.setFont(u8g2_font_6x10_tf);
        display.drawText(80, 27, "Monday");

        // --- Ícono de clima ---
        display.drawGlyph(68, 18, u8g2_font_open_iconic_all_2x_t, 0x0103);

        // --- Selector de íconos ---
        display.highlightBox((slider.getIconsSelector() * 32), 32, 32, 32);
    }
};
