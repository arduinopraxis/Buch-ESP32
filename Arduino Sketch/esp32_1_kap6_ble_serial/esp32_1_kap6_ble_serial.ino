//
// ESP32 - BLE Serial
// Datei: esp32_1_kap6_ble_serial.ino

#include <BLESerial.h>

// FOR ETL: Uncomment the following lines
// #include <Embedded_Template_Library.h>
// #include <etl/queue.h>
// #include <etl/circular_buffer.h>

// Device-Name
String device_name = "ESP32-BLE-Slave";

// BLE-Objekt
BLESerial SerialBLE;


void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600);
  // BLE Seriell
  SerialBLE.begin(device_name);
}

void loop() 
{
  // Falls Serielle Daten vorhanden, senden an BLE
  
  if (Serial.available()) {
    SerialBLE.write(Serial.read());
    SerialBLE.flush();
    }
    // falls BLE-Daten, senden an Seriell
    if (SerialBLE.available()) {
      Serial.write(SerialBLE.read());
    }
}