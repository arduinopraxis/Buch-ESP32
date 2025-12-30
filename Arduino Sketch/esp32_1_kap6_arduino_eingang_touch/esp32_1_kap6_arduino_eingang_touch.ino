// ESP32 - Eingang Touch
// Datei: esp32_1_kap6_arduino_eingang_touch.ino

const int tPin=4;  // T0 = GPIO4
const int LEDPin=2;
int tWert=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() 
{
  tWert = touchRead(tPin);
  Serial.println(tWert);
  // Aktion abhängig von Wert tWert
  if (tWert < 10) {
    digitalWrite(LEDPin, LOW);
    }
    else
    {
      digitalWrite(LEDPin, HIGH);
    }
  delay(100);
}
