//
// ESP32 - DAC Ausgabe
// Datei: esp32_1_kap6_dac_ausgabe.ino


const int DACPin1 = 25;
const int DACPin2 = 26;
int DACWert = 124;

void setup() 
{
  // keine Einstellungen notwendig
}

void loop() 
{
  // DAC1 = GPIO25
  // Ausgabe Wert
  dacWrite(DACPin1, DACWert);
  delay(1000);

  // Ausgabe 0 - 255/ 0-3.3V
  for (int i = 0; i <= 255; i++) {
    dacWrite(DACPin1, i);
    delay(10);
  }
  
}
