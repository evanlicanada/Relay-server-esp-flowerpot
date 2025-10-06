#include "led_control.h"

LEDController::LEDController(int rPin, int gPin, int bPin) {
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
void LEDController::setRgb(int redValue, int greenValue, int blueValue) {
    // Write the PWM duty cycle to each channel, controlling the brightness.
    currentRed = redValue;
    currentGreen = greenValue;
    currentBlue = blueValue;
    ledcWrite(redChannel, redValue);
    ledcWrite(greenChannel, greenValue);
    ledcWrite(blueChannel, blueValue);
}

void LEDController::fadeToColor(int targetRed, int targetGreen, int targetBlue, int steps, int delayTime) {

    int stepRed = (targetRed - currentRed) / steps;
    int stepGreen = (targetGreen - currentGreen) / steps;
    int stepBlue = (targetBlue - currentBlue) / steps;

    for (int i = 0; i <= steps; i++) {
        int newRed = currentRed + stepRed * i;
        int newGreen = currentGreen + stepGreen * i;
        int newBlue = currentBlue + stepBlue * i;

        setRgb(newRed, newGreen, newBlue);
        delay(delayTime);
    }
}