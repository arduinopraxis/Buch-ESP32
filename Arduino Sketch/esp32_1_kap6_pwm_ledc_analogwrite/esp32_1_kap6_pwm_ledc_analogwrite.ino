//
// ESP32 - Analog Out mit LEDC mit analogWrite
// Datei: esp32_1_kap6_pwm_ledc_analogwrite.ino

const int LEDCh = 0;
const int LEDPin = 10; // GPIO10 = D10
const int freq = 1000; // 1000 Hertz
const int res = 12;

// Arduino like analogWrite
// Ausgabewert zwischen 0 und valueMax
void ledcAnalogWrite(uint8_t pin, uint32_t value, uint32_t valueMax = 255) {
  // calculate duty, 4095 from 2 ^ 12 - 1
  uint32_t duty = (4095 / valueMax) * min(value, valueMax);

  // Duty in LEDC ausgeben
  ledcWrite(pin, duty);
}

void setup() 
{
  // LEDC Objekt
  ledcAttach(LEDPin, freq, res);
}

void loop() 
{
  // Analog Ausgabe Channel1
  // Wert 2000, Maximalwert 4095
  ledcAnalogWrite(LEDPin, 2000, 4095);
  
  // warten
  delay(100);
}

