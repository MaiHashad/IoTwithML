#include <DiagnosticsHelperRK.h>

SYSTEM_THREAD(ENABLED);

const int pinLight = A0;
const int pinLed = 7;

const int thresholdvalue=200;  
const unsigned long UPDATE_INTERVAL = 2000;
unsigned long lastUpdate = 0;



// Private battery and power service UUID
const BleUuid serviceUuid("3f0d7b3a-7c2b-41d3-9378-186283fbc6a9");

BleCharacteristic uptimeCharacteristic("uptime", BleCharacteristicProperty::NOTIFY, BleUuid("fdcf4a3f-3fed-4ed2-84e6-04bbb9ae04d4"), serviceUuid);
BleCharacteristic signalStrengthCharacteristic("strength", BleCharacteristicProperty::NOTIFY, BleUuid("cc97c20c-5822-4800-ade5-1f661d2133ee"), serviceUuid);
BleCharacteristic freeMemoryCharacteristic("freeMemory", BleCharacteristicProperty::NOTIFY, BleUuid("d2b26bf3-9792-42fc-9e8a-41f6107df04c"), serviceUuid);


void configureBLE()
{
    BLE.addCharacteristic(uptimeCharacteristic);
    BLE.addCharacteristic(signalStrengthCharacteristic);
    BLE.addCharacteristic(freeMemoryCharacteristic);
    BleAdvertisingData advData;
    // Advertise our private service only
    advData.appendServiceUUID(serviceUuid);

    // Continuously advertise when not connected
    BLE.advertise(&advData);
}

void setup()
{
    pinMode(pinLed, OUTPUT);
	Serial.begin(9600);  
    configureBLE();          
}

void loop()
{
    unsigned long currentMillis = millis();
    
    if (currentMillis - lastUpdate >= UPDATE_INTERVAL)
    {
        lastUpdate = millis();
        int sensorValue = analogRead(pinLight); 
        if (sensorValue < thresholdvalue){
            digitalWrite(pinLed, HIGH);
        }
        else{
            digitalWrite(pinLed, LOW);
        }
  
        Serial.println(sensorValue);
    }
    if (BLE.connected())
    {
        uint8_t uptime = (uint8_t)DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_UPTIME);
        uptimeCharacteristic.setValue(uptime);

        uint8_t signalStrength = (uint8_t)(DiagnosticsHelper::getValue(DIAG_ID_NETWORK_SIGNAL_STRENGTH) >> 8);
        signalStrengthCharacteristic.setValue(signalStrength);
        
        int32_t usedRAM = DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_USED_RAM);
        int32_t totalRAM = DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_TOTAL_RAM);
        int32_t freeMem = (totalRAM - usedRAM);
        freeMemoryCharacteristic.setValue(freeMem);
    }
}
