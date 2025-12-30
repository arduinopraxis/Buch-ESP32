// ESP32 - Digitaler Ausgang
// Datei: esp32_1_kap6_arduino_ausgang.ino
// Board: XIAO ESP32-C3

const int LEDPin=10; // GPIO10 = D10

void setup() 
{
  // Ausgang
  pinMode(LEDPin, OUTPUT);
}

void loop() 
{
  // Ausgang EIN 
  digitalWrite(LEDPin, HIGH);
  delay(500);
  // Ausgang AUS
  digitalWrite(LEDPin, LOW);
  delay(500);
}