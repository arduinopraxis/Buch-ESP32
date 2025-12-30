// ESP32 - Serielle Ausgabe
// Datei: esp32_1_kap4_serial_ausgabe.ino

void setup()
{
  Serial.begin(9600); // Konfiguration serielle Schnittstelle
}


void loop()
{
  Serial.println("Hallo ESP32 Welt"); // Ausgabe
}
