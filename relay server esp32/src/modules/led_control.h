#pragma once

#include <Arduino.h>

// This program controls the brightness of RGB LEDs using Pulse-Width Modulation (PWM) on an ESP32.
// It uses the built-in LED Control (LEDC) peripheral of the ESP32.

// Define the GPIO pins connected to the LEDs.
// A common cathode configuration is assumed, where the long leg of the LEDs is connected to GND.
// If you are using a common anode configuration (long leg to VCC), you will need to
// invert the PWM duty cycle values (e.g., use 255 - brightness).
const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;

// Define the PWM channels for each color.
// The ESP32 has 16 independent PWM channels (0-15).
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

// Define the PWM properties.
// The frequency is how many times the PWM signal cycles per second. 5000 Hz is good to avoid flicker.
const int freq = 5000;
// The resolution determines the range of the brightness value. 8 bits gives a range from 0 to 255.
const int resolution = 8;
const int maxDutyCycle = 255; // The maximum value for an 8-bit resolution.


class LEDController {
    public:

        int currentRed = 0;
        int currentGreen = 0;
        int currentBlue = 0;
        
        LEDController(int redPin, int greenPin, int bluePin);
        void setRgb(int redValue, int greenValue, int blueValue);
        void fadeToColor(int targetRed, int targetGreen, int targetBlue, int steps, int delayTime);

};