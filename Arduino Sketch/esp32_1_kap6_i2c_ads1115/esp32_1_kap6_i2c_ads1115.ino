//
// ESP32 - ADC-Modul mit ADS1115
// Datei: esp32_1_kap6_i2c_ads1115.ino

#include <Wire.h>
#include <Adafruit_ADS1X15.h>

// ADC-Objekt
Adafruit_ADS1115 adcmodul;

#define I2C_SDA 6
#define I2C_SCL 7

void setup(void) 
{
  // Serielle Schnittstelle
  Serial.begin(115200);

  // I2C-Bus initialisieren
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!adcmodul.begin(0x48)) {
    Serial.println("ADS1115-Modul nicht gefunden..");
    while (1);
  }

  adcmodul.setGain(GAIN_ONE);  // +/-4.096V Bereich (Standard)
  Serial.println("ADS1115 gestartet...");
}

void loop(void) 
{
  int16_t adc0 = adcmodul.readADC_SingleEnded(0);
  float v0 = adc0 * 0.125; // mV (bei GAIN_ONE = 0.125mV/LSB)
  // Umrechung in V
  v0 = v0/1000.0;

  Serial.print("ADC0: ");
  Serial.print(adc0);
  Serial.print(", Spannung: ");
  Serial.print(v0);
  Serial.println(" V");

  delay(1000);
}


