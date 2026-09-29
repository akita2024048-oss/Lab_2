


#include "Arduino.h"

const uint8_t BUTTON_PIN = 25;
const uint8_t LED_PINS[] = {26, 27, 12, 14};
const uint8_t LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const unsigned long DEBOUNCE_MS = 30;

bool buttonStableState = LOW;
bool lastButtonReading = LOW;
uint8_t pressCount = 0;
unsigned long lastDebounceTime = 0;

/****************************************************/
void setup(void) 
{
	Serial.begin(115200);
	pinMode(BUTTON_PIN, INPUT);

	for (uint8_t index = 0; index < LED_COUNT; ++index) {
		pinMode(LED_PINS[index], OUTPUT);
		digitalWrite(LED_PINS[index], LOW);
	}
}


/****************************************************/
void loop(void) 
{
	const bool buttonReading = digitalRead(BUTTON_PIN);

	if (buttonReading != lastButtonReading) {
		lastDebounceTime = millis();
		lastButtonReading = buttonReading;
	}

	if (millis() - lastDebounceTime >= DEBOUNCE_MS &&
		buttonReading != buttonStableState) {
		buttonStableState = buttonReading;

		if (buttonStableState == HIGH) {
			pressCount = (pressCount + 1) % (LED_COUNT + 1);
			Serial.print("count=");
			Serial.println(pressCount);

			for (uint8_t index = 0; index < LED_COUNT; ++index) {
				digitalWrite(LED_PINS[index], pressCount > index ? HIGH : LOW);
			}
		}
	}
}
