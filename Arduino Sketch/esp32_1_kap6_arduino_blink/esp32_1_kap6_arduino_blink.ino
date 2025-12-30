// ESP32 - Blink
// Datei: esp32_1_kap6_arduino_blink.ino
// Board: ESP32-C6-Bug

// Onboard LED GPIO9
//const int LEDPin = 23;
// XIAO ESP32-C3
const int LEDPin = D0;

void setup() // Setup
{
  pinMode(LEDPin, OUTPUT);
}

void loop() // Schleife durch das Hauptprogramm
{
  digitalWrite(LEDPin, HIGH);   // LED einschalten
  delay(1000);                  // 1 Sekunde warten
  digitalWrite(LEDPin, LOW);    // LED ausschalten
  delay(500);                  // 0.5 Sekunden warten
  // und weiter geht's am Start der Schleife
}
