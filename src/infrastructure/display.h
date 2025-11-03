#pragma once
#include <U8g2lib.h>
#include "Pins.h"

class Display
{
private:
    U8G2_ST7920_128X64_F_SW_SPI u8g2;

public:
    Display()
        : u8g2(U8G2_R0, LCD_CLOCK, LCD_DATA, LCD_CS, LCD_RESET) {}

    void firstPage() { u8g2.firstPage(); }

    uint8_t nextPage() { return u8g2.nextPage(); }

    void begin() { u8g2.begin(); }

    void clear() { u8g2.clearBuffer(); }

    void render() { u8g2.sendBuffer(); }

    void setCursor(int x, int y) { u8g2.setCursor(x, y); }

    void print(const String &s) { u8g2.print(s); };

    void setColor(int color) { u8g2.setDrawColor(color); }

    void setFontMode(int mode) { u8g2.setFontMode(mode); }

    void drawFrame(int x, int y, int w, int h, int r = 0) { u8g2.drawRFrame(x, y, w, h, r); }

    void drawBox(int x, int y, int w, int h) { u8g2.drawBox(x, y, w, h); }

    void drawLine(int x1, int y1, int x2, int y2) { u8g2.drawLine(x1, y1, x2, y2); }

    void setFont(const uint8_t *font = u8g2_font_6x10_tf) { u8g2.setFont(font); }

    void drawText(int x, int y, const char *text) { u8g2.drawStr(x, y, text); }

    void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) { u8g2.drawTriangle(x0, y0, x1, y1, x2, y2); }

    void drawBitmap(int x, int y, int width, int height, const uint8_t *bitmap, int mode = 1)
    {
        u8g2.setBitmapMode(mode);
        u8g2.drawXBMP(x, y, width, height, bitmap);
    }

    void drawGlyph(int x, int y, const uint8_t *font, uint16_t glyph)
    {
        u8g2.setFont(font);
        u8g2.drawGlyph(x, y, glyph);
    }

    void highlightBox(int x, int y, int w, int h)
    {
        u8g2.setDrawColor(2);
        u8g2.drawBox(x, y, w, h);
    }
};
