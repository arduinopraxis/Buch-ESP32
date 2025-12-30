//
// ESP32 - PT100 Temperatursensor
// Datei: esp32_1_kap6_spi_pt100_tempsensor.ino

#include <Adafruit_MAX31865.h>

// Tempsensor Objekt
// Pins: CS, MOSI, MISO, SCK
Adafruit_MAX31865 pt100 = Adafruit_MAX31865(20, 10, 9, 8); 

// Referenzwert, 430.0 für PT100 und  4300.0 für PT1000
#define RREF      430.0
// Nominalwert bei 0 Grad C
#define RNOMINAL  100.0

void setup() 
{
  Serial.begin(115200);
  Serial.println("PT100 - Temperaturmessung...");

  // Temperaturmessung starten
  pt100.begin(MAX31865_2WIRE); 
}

void loop() 
{
  // Sensor einlesen
  uint16_t rtd = pt100.readRTD();
  float ratio = rtd;
  ratio /= 32768;
  Serial.print("Widerstand: "); 
  Serial.println(RREF*ratio,8);
  Serial.print("Temp: "); 
  Serial.println(pt100.temperature(RNOMINAL, RREF));

  // Prüfung und Fehlerausgabe
  uint8_t fault = pt100.readFault();
  if (fault) {
    Serial.print("Fault 0x"); 
    Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    pt100.clearFault();
  }
 
  // Warten
  delay(1000);
}
