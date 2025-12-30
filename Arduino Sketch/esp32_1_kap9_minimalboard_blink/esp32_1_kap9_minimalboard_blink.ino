// ESP32 - Blink
// Datei: esp32_1_kap9_minimalboard_blink.ino
// Datum: 09.05.25


int LEDPin = 2;

void setup() 
{
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  digitalWrite(LEDPin, HIGH);
  delay(200);
  digitalWrite(LEDPin, LOW);
  delay(200);
}
