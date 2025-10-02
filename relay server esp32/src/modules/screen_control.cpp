#include "screen_control.h"

void LCD_Screen::blink(int openTime, int closeTime){
    tft.setTextSize(40);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(10, 200);
    tft.println("--");
    delay(closeTime);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(10, 200);
    tft.println("00");
    delay(openTime);
}

void LCD_Screen::happy_eyes(int activeTime){
    tft.setTextSize(40);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(10, 200);
    tft.println("^^");
    delay(activeTime);
}

//14 characters per line
//6 total lines
void LCD_Screen::showText(String text){
  tft.setFreeFont(&FreeMonoBold9pt7b);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 30);
  tft.println(text);
}

