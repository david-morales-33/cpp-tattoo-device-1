#pragma once
#include <U8g2lib.h>
#include "Pins.h"

class Display
{
private:
    U8G2_ST7920_128X64_F_SW_SPI u8g2;

public:
    Display() : u8g2(U8G2_R0, LCD_CLOCK, LCD_DATA, LCD_CS, LCD_RESET) {}

    void begin()
    {
        u8g2.begin();
    }

    void clear()
    {
        u8g2.clearBuffer();
    }

    void drawBitmap(int x, int y, int w, int h, const unsigned char *bitmap)
    {
        u8g2.drawXBMP(x, y, w, h, bitmap);
    }

    void drawText(int x, int y, const uint8_t *font_txt, const char *text)
    {
        u8g2.setFont(font_txt);
        u8g2.drawStr(x, y, text);
    }

    void render()
    {
        u8g2.sendBuffer();
    }
};
