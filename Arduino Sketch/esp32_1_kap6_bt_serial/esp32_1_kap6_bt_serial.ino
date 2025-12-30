//
// ESP32 - Bluetooth Serial
// Datei: esp32_1_kap6_bt_serial.ino

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);

  // Name Bluetooth
  SerialBT.begin("ESP32_BT");
  Serial.println("Bluetooth-Gerät ist bereit. Verbinde dich mit 'ESP32_BT'");
}

void loop() 
{
  if (Serial.available()) {
    SerialBT.write(Serial.read()); // Sende über BT
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read()); // Empfange von BT
  }
  delay(20);
}
