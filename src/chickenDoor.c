#include <stdio.h>
#include <wiringPi.h>

// Pin number declaration (WiringPi scheme)
#define LED_PIN 0  // GPIO 17 in WiringPi is pin 0

int main(void) {
    // Setup stuff:
    wiringPiSetup();  // Initialize wiringPi
    pinMode(LED_PIN, OUTPUT);  // Set pin as output

    while(1) {
        digitalWrite(LED_PIN, HIGH);  // Turn LED on
        delay(500);  // Wait 500ms
        digitalWrite(LED_PIN, LOW);  // Turn LED off
        delay(500);  // Wait 500ms
    }

    return 0;
}


