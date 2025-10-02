#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

#define BL 19  // Backlight pin
#define FACETEXTSIZE 40

class LCD_Screen{
    public:
        TFT_eSPI tft = TFT_eSPI();
        LCD_Screen(TFT_eSPI tft){
            // Initialize backlight to full brightness
            pinMode(BL, OUTPUT);
            digitalWrite(BL, HIGH);  // or use PWM if you want dimming

            // Initialize TFT
            tft.init();
            tft.setRotation(3);  // try 0,1,2,3 if needed
            tft.fillScreen(TFT_BLACK);

            // // Fill screen with solid colors for testing
            // tft.fillScreen(TFT_RED);
            // delay(1000);
            // tft.fillScreen(TFT_GREEN);
            // delay(1000);
            // tft.fillScreen(TFT_BLUE);
            // delay(1000);

            // Draw text
            tft.setFreeFont(&FreeMonoBold18pt7b);
            tft.fillScreen(TFT_BLACK);
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.setTextSize(FACETEXTSIZE);
        }

        void blink(int openTime, int closeTime);
        void happy_eyes(int activeTime);
        void showText(String text);


    
};