#include <math.h>
#include <Grove_ChainableLED.h>                 // RGB LED library

ChainableLED leds(D2, D3, 1); // LED object constructor
const int thresholdvalue=10; //The threshold for which the LED should turn on. 
float Rsensor;

void setup()
{
	Serial.begin(9600);             // Begin serial communications
    leds.init();                    // initialise the LED
}

void loop()
{

  int sensorValue = analogRead(0); 
  Serial.println(sensorValue);
  if (sensorValue < 300){
      leds.setColorRGB(0, 0, 0, 0);
  }
  else{
       leds.setColorRGB(0, 0, 255, 0);
  }

  delay(100);
}

  //Rsensor = (float)(1023-sensorValue)*10/sensorValue;
  
  //if(Rsensor<thresholdvalue)
  //{
  //  leds.setColorRGB(0, 0, 0, 0);                         // off
  //}
  //else
  //{
//      leds.setColorRGB(0, 255, 0, 0);                         // red
  //}
  //Serial.println("the analog read data is ");
  //Serial.println(sensorValue);
  //Serial.println("the sensor resistance is ");
  //Serial.println(Rsensor,DEC);//show the light intensity on the serial monitor;
