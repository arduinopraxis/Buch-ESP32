// ESP32 - Blink
// Datei: esp32_1_kap4_arduino_blink.ino

const int LEDPin = 2;

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
