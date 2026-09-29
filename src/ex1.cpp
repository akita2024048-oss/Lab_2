


#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

const uint8_t LED_PINS[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};
const char* LED_NAMES[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
const uint8_t STEP_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
uint8_t stepIndex = 0;

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}


/****************************************************/
void loop(void) 
{
    const uint8_t pin = LED_PINS[stepIndex];
    digitalWrite(pin, HIGH);
    Serial.print("chase=");
    Serial.println(LED_NAMES[stepIndex]);
    delay(150);
    digitalWrite(pin, LOW);

    stepIndex = (stepIndex + 1) % STEP_COUNT;
}
