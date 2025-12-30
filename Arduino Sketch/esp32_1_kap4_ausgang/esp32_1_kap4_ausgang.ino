// ESP32 - Ausgang
// Datei: esp32_1_kap4_ausgang.ino

const int InpPin = 2;
const int OutPin = 6;
int status = 0;

void setup() 
{
  // Eingang setzen
  pinMode(InpPin, INPUT);
  // Ausgang setzen
  pinMode(OutPin, OUTPUT);
  //
  //Anweisung
}

void loop() 
{
  // Eingang einlesen
  status = digitalRead(InpPin);

  // Eingang prüfen ob Ein oder Aus
  if (status == HIGH) {
    // Ausgang Ein
    digitalWrite(OutPin, HIGH);
  } else {
    // Ausgang Aus
    digitalWrite(OutPin, LOW);
  }
}
