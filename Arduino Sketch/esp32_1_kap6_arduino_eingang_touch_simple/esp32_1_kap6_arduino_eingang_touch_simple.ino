// ESP32 - Eingang Touch
// Datei: esp32_1_kap6_arduino_eingang_touch_simple.ino

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int tWert = touchRead(4); // T0 = GPIO4
  Serial.println(tWert);
  delay(100);
}
