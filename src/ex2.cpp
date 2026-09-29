


#include "Arduino.h"

const uint8_t LIGHT_PIN = 33;
const uint8_t SAMPLE_COUNT = 10;

/****************************************************/
void setup(void) 
{
	Serial.begin(115200);
	pinMode(LIGHT_PIN, INPUT);
}


/****************************************************/
void loop(void) 
{
	int minimum = analogRead(LIGHT_PIN);
	int maximum = minimum;
	long total = minimum;

	for (uint8_t sampleIndex = 1; sampleIndex < SAMPLE_COUNT; ++sampleIndex) {
		const int sample = analogRead(LIGHT_PIN);
		if (sample < minimum) {
			minimum = sample;
		}
		if (sample > maximum) {
			maximum = sample;
		}
		total += sample;
	}

	Serial.print("min=");
	Serial.print(minimum);
	Serial.print(" max=");
	Serial.print(maximum);
	Serial.print(" avg=");
	Serial.println(total / SAMPLE_COUNT);

	delay(1000);
}
