// ESP32 - Eingang
// Datei: esp32_1_kap4_eingang.ino

const int InpPin = 2;
int status = 0;

void setup() 
{
  pinMode(InpPin, INPUT);
  //
  //Anweisung
}

void loop() 
{
  // Eingang einlesen
  status = digitalRead(InpPin);

  // Eingang prüfen ob Ein oder Aus
  if (status == HIGH) {
    // mach etwas bei EIN
    //
  } else {
    // mach etwas bei AUS
    //
  }
}
