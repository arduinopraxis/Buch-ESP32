//
// ESP32 - SHT3x via I2c
// Datei: esp32_1_kap6_i2c_sht3x.ino

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

// Sensor-Objekt
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600);

  // Kurz warten, Schnittstelle bereit
  while (!Serial)
    delay(10);

  // Ausgabe Server-Initialisierung
  // Meldung, falls Sensor an Standard-Adresse nicht verfügbar
  Serial.println("SHT31 Sensor...");
  if (! sht31.begin(0x44)) {   
    Serial.println("Kein SHT31 gefunden...");
    while (1) delay(1);
  }
}


void loop() 
{
  // Daten einlesen
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) {  // Prüfen, ob keine Zahl
    Serial.print("T: "); 
    Serial.print(t); 
    Serial.println(" C");
  } else { 
    Serial.println("Fehler bei Abfrage Temperatur T");
  }
  
  if (! isnan(h)) {  // Prüfen, ob keine Zahl
    Serial.print("H: "); 
    Serial.print(h);
    Serial.println(" %");
  } else { 
    Serial.println("Fehler bei Abfrage Luftfeuchtigkeit H");
  }

  // Warten
  delay(1000);
}



