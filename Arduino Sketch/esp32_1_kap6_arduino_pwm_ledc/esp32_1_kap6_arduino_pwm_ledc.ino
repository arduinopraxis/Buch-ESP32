// ESP32 - Analoger Ausgang mit PWM
// Datei: esp32_1_kap6_arduino_pwm_ledc.ino
// Board: XIAO ESP32-C3

const int LEDCh = 0;
const int LEDPin = 10; // GPIO4 = D2
const int freq = 5000;
const int res = 8;


void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(9600); 
  // LEDC Channel
  ledcAttachChannel(LEDPin, freq, res, LEDCh);
}


void loop() 
{
  ledcWrite(LEDCh, 125);
  /*
  // Helligkeit von 0 bis 255 hochzählen
  for (int duty = 0; duty <= 255; duty++) {
    ledcWrite(LEDCh, duty);
    Serial.println(duty);
    delay(100);
  }
  */
}

