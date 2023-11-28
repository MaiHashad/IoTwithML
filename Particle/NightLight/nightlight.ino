const int pinLight = A0;
const int pinLed = 7;

const int thresholdvalue=200;  

void setup()
{
    pinMode(pinLed, OUTPUT);
	Serial.begin(9600);            
}

void loop()
{

  int sensorValue = analogRead(pinLight); 
  
  if (sensorValue < thresholdvalue){
      digitalWrite(pinLed, HIGH);
  }
  else{
       digitalWrite(pinLed, LOW);
  }
  
  Serial.println(sensorValue);
  delay(100);
}

