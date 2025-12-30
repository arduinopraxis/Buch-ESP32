//
// ESP32 - SPI Pins abfragen
// Datei: esp32_1_kap6_spi_pins.ino


void setup() 
{
  // Start serielle Schnittstelle
  Serial.begin(115200);

  // Ausgabe SPI Pins
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);  
}

void loop() {
  // Anweisungen
}