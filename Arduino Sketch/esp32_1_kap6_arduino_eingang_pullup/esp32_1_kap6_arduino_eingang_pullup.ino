// ESP32 - Digitaler Eingang mit Pullup
// Datei: esp32_1_kap6_arduino_eingang_pullup.ino
// Board: XIAO ESP32-C3

const int tasterPin=2; // GPIO2 = D0

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600); 
  // Eingang
  pinMode(tasterPin, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(tasterPin) == LOW) {
    // Taster gedrückt, Aktion ausführen
    Serial.println("Taste gedrückt");
  }
  delay(1000);
}