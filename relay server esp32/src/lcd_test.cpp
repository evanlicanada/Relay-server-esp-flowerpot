#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();  // Uses your User_Setup.h

#define BL 19  // Backlight pin

int counter = 0;

void setup() {
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
  tft.setTextSize(40);
}

void blink(int openTime, int closeTime){
  tft.setFreeFont(&FreeMonoBold18pt7b);
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

void happy_eyes(int activeTime){
  tft.setFreeFont(&FreeMonoBold18pt7b);
  tft.setTextSize(40);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 200);
  tft.println("^^");
  delay(activeTime);
}

//14 characters per line
//6 total lines
void showText(String text, int textSize){
  tft.setFreeFont(&FreeMonoBold9pt7b);
  tft.setTextSize(textSize);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, textSize*10 + 10);
  tft.println(text);
}

void loop() {
  showText("Good\nMorning\nBaby!", 3);
  delay(10000);
}
