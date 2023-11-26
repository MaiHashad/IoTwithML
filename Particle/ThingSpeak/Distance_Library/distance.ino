// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>

// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>


Ultrasonic ultrasonic(4);
TCPClient client;

unsigned long myChannelNumber = 2359145;    // change this to your channel number
const char * myWriteAPIKey = "LV7QCXL49SYB5P3R"; // change this to your channels write API key

void setup() {
    ThingSpeak.begin(client); 
    Serial.begin(9600);
}

void loop() {
    
    //long RangeInCentimeters;
    Serial.println("The distance to obstacles in front is: ");
    //RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    //String distance = String(RangeInCentimeters);
    String distance = String(randome(60,90));
    Serial.println(distance);
    ThingSpeak.writeField(myChannelNumber, 1, distance, myWriteAPIKey);
    delay(20000); // ThingSpeak will only accept updates every 15 seconds.

}