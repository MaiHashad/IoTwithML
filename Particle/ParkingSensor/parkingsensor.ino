#include <Grove_ChainableLED.h>                 // RGB LED library
#include <Grove-Ultrasonic-Ranger.h>            // Ultrasonic Ranger library

float distance = 10.0;             // close range boundary

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

	
	if (RangeInCentimeters > distance){                        // If range is greater than far boundary...
	    leds.setColorRGB(0, 0, 0, 0);                         // off
	}
	else if(RangeInCentimeters <= distance) {                  // close...
	    leds.setColorRGB(0, 255, 0, 0);                         // red
	    Serial.println("The car is parked!");
	    Particle.publish("The car is parked");
	}
	
	delay(100);                     // small delay, so the sensor has some time to do it's thing
}
