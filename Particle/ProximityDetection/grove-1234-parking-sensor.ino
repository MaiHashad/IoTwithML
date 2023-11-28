#include <Grove_ChainableLED.h>     // RGB LED library
#include "Ultrasonic.h"             // Ultrasonic Ranger library

float distance2 = 50.0;             // far range boundary
float distance1 = 20.0;             // close range boundary

Ultrasonic ultrasonic(D4);          // Ultrasonic object constructor
ChainableLED leds(D2, D3, 1);       // LED object constructor

void setup()
{
	Serial.begin(9600);             // Begin serial communications
    leds.init();                    // initialise the LED
}

void loop()
{
	long RangeInCentimeters;        // Variable to hold the distance measurement

	RangeInCentimeters = ultrasonic.MeasureInCentimeters();     // Get the current distance value
	Serial.print(RangeInCentimeters);                           // Out put the value over serial
	Serial.println(" cm"); // use 'particle serial monitor --follow' in the CLI to see serial output
	
	if (RangeInCentimeters > distance2){                        // If range is greater than far boundary...
	    leds.setColorRGB(0, 0, 255, 0);                         // green
	}
	else if (RangeInCentimeters < distance2 && RangeInCentimeters > distance1) { // range between far and close...
	    leds.setColorRGB(0, 255, 165, 0);                       // orange
	}
	else if (RangeInCentimeters < distance1) {                  // too close...
	    leds.setColorRGB(0, 255, 0, 0);                         // red
	}
	
	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
