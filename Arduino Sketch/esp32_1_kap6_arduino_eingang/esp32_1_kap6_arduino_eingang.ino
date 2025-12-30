// ESP32 - Digitaler Eingang
// Datei: esp32_1_kap6_arduino_eingang.ino
// Board: XIAO ESP32-C3

const int tasterPin=2; // GPIO2 = D0

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600); 
  // Eingang
  pinMode(tasterPin, INPUT);
}

void loop() 
{
  if (digitalRead(tasterPin) == HIGH) {
    // Taster gedrückt, Aktion ausführen
    Serial.println("Taste auf HIGH");
  }
  delay(1000);
}