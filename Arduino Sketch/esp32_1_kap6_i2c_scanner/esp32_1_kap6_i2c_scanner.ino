#include <Wire.h>

#define I2C_SDA 6
#define I2C_SCL 7

void setup() {
  Serial.begin(115200);

  // I2C-Bus initialisieren
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("I2C Bus gestartet");
}

void loop() {
  // Beispiel: I2C-Scan
  byte error, address;
  int nDevices = 0;

  Serial.println("I2C-Scan startet...");

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C-Gerät gefunden bei Adresse 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("Keine I2C-Geräte gefunden");
  else
    Serial.println("Scan abgeschlossen");

  delay(5000);
}
