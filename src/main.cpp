#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/18, /* data=*/23, /* CS=*/5, /* reset=*/22);  // ESP32

#define width 26
#define height 26
#define ENTER 4
#define BACK 2
#define UP 14
#define DOWN 33
#define RIGH 32
#define LEFT 27


void setup() {
 
}

void loop() {

}
