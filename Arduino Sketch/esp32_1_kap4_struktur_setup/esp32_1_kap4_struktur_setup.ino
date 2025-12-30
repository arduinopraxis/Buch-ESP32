// ESP32 - Arduino Struktur und Setup
// Datei: esp32_1_kap4_struktur_setup.ino

const int ledPin = 2; // LED an Pin 2
const int buttonPin = 4; // Button an Pin 4

void setup()
{
  // Pin 2 als Ausgang
  pinMode(ledPin, OUTPUT); 
  // Pin 4 als Eingang
  pinMode(buttonPin, INPUT); 
  // Initialisierung der seriellen Schnittstelle
  Serial.begin(9600); 
}

