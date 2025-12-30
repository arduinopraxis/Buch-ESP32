//
// ESP32 - SPI Daten senden/empfangen
// Datei: esp32_1_kap6_spi_struktur.ino

#include <SPI.h>

// Chip Select
#define CSPin 20

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);

  // SPI starten
  // SCK, MISO, MOSI, CS
  // ESP32 Standard
  // SPI.begin(18, 19, 23, CSPin);
  // XIAO ESP32-C3
  SPI.begin(8, 9, 10, CSPin);

  pinMode(CSPin, OUTPUT);
  digitalWrite(CSPin, HIGH);
}

void loop() 
{
  byte sendData = 0x24;
  byte recData;

  digitalWrite(CSPin, LOW);
  // Daten senden und empfangen
  recData = SPI.transfer(sendData);
  digitalWrite(CSPin, HIGH);

  // Ausgabe
  Serial.print("Gesendet: 0x");
  Serial.println(sendData, HEX);
  Serial.print("Empfangen: 0x");
  Serial.println(recData, HEX);

  delay(1000);
}

