//
// ESP32 - I2C Struktur
// Datei: esp32_1_kap6_i2c_struktur.ino

#include <Wire.h>

#define I2C_SDA 6
#define I2C_SCL 7

void setup() 
{
  // I2C-Bus initialisieren
  Wire.begin(I2C_SDA, I2C_SCL);
}

void loop() 
{
  
}
