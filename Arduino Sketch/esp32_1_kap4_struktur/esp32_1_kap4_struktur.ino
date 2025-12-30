// ESP32 - Arduino Struktur
// Datei: esp32_1_kap4_struktur.ino

int ledPin = 13; // LED an Pin 13
int buttonPin = 2; // Button an Pin 2
void setup()
{
pinMode(ledPin, OUTPUT); // Pin 13 als Ausgang
pinMode(buttonPin, INPUT); // Pin 2 als Eingang
Serial.begin(9600); //
Initialisierung der seriellen Schnittstelle
}
