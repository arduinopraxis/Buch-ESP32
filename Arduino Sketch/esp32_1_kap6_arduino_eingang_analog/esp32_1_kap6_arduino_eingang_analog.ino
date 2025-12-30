// ESP32 - Analoge Eingänge
// Datei: esp32_1_kap6_arduino_eingang_analog.ino
// Board: XIAO ESP32-C3

const int analogPin = 4;  // A2 an GPIO4
int aWert = 0;

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600); 
}

void loop() 
{
  // Analogwert einlesen
  aWert = analogRead(analogPin);
  // Ausgabe
  Serial.println(aWert);
  delay(100);
}










