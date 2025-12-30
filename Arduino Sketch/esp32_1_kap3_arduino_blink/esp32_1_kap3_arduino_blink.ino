// ESP32 - Blink
// Datei: 555_esp32_blink.ino

int LEDPin = 2;

void setup() 
{
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LEDPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
