


#include "Arduino.h"

const uint8_t LIGHT_PIN = 33;
bool alertActive = false;

/****************************************************/
void setup(void) 
{
	Serial.begin(115200);
	pinMode(LIGHT_PIN, INPUT);
}


/****************************************************/
void loop(void) 
{
	const int lightReading = analogRead(LIGHT_PIN);

	if (!alertActive && lightReading > 3000) {
		alertActive = true;
		Serial.println("ALERT=1");
	} else if (alertActive && lightReading < 2500) {
		alertActive = false;
		Serial.println("ALERT=0");
	}

	delay(300);
}
