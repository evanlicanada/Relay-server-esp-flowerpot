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

void setup() {
  Serial.begin(115200);

  // Configure the PWM channels for the specified frequency and resolution.
  // This sets up the timer for the PWM signal.
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);

  // Attach the PWM channels to the GPIO pins.
  // This links the PWM signal to the physical pin.
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
}

// Function to set the brightness of the RGB LEDs.
// Takes three integer values (0-255) for red, green, and blue.
void setRgb(int redValue, int greenValue, int blueValue) {
  // Write the PWM duty cycle to each channel, controlling the brightness.
  ledcWrite(redChannel, redValue);
  ledcWrite(greenChannel, greenValue);
  ledcWrite(blueChannel, blueValue);
}

void loop() {
  // Fade in and out with different colors to demonstrate PWM.

  // Fade red from 0 to 255 and back down to 0
  for (int brightness = 0; brightness <= maxDutyCycle; brightness++) {
    setRgb(brightness, 0, 0);
    delay(5);
  }
  for (int brightness = maxDutyCycle; brightness >= 0; brightness--) {
    setRgb(brightness, 0, 0);
    delay(5);
  }

  // Fade green from 0 to 255 and back down to 0
  for (int brightness = 0; brightness <= maxDutyCycle; brightness++) {
    setRgb(0, brightness, 0);
    delay(5);
  }
  for (int brightness = maxDutyCycle; brightness >= 0; brightness--) {
    setRgb(0, brightness, 0);
    delay(5);
  }

  // Fade blue from 0 to 255 and back down to 0
  for (int brightness = 0; brightness <= maxDutyCycle; brightness++) {
    setRgb(0, 0, brightness);
    delay(5);
  }
  for (int brightness = maxDutyCycle; brightness >= 0; brightness--) {
    setRgb(0, 0, brightness);
    delay(5);
  }

  // Fade from red to magenta to blue to cyan to green to yellow to red.
  for (int red = 0; red < maxDutyCycle; red++) {
    setRgb(red, 0, maxDutyCycle - red);
    delay(5);
  }
  for (int green = 0; green < maxDutyCycle; green++) {
    setRgb(maxDutyCycle - green, green, 0);
    delay(5);
  }
  for (int blue = 0; blue < maxDutyCycle; blue++) {
    setRgb(0, maxDutyCycle - blue, blue);
    delay(5);
  }
}
