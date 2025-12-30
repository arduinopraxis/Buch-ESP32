// ESP32 - OTA Blink 
// Datei: 555_esp32_Blink_OTA.ino
// Datum: 04.09.25
// IDE: 1.8.13
// Board: ESP32 Minimal (8)
//
// Status: OK

// Bibliotheken
#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "ObiWifinobi";
const char* password = "crisi7s-stRike-Plus";

int LEDPin = 2;

void setup() 
{
  WiFi.begin(ssid, password);

  // Wifi verbunden
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Start OTA
  ArduinoOTA.begin();

  // Pin Konfiguration
  pinMode(LEDPin, OUTPUT);
}

void loop() 
{
  // Update verarbieten
  ArduinoOTA.handle();

  // Code Blink
  digitalWrite(LEDPin, HIGH);
  delay(100);
  digitalWrite(LEDPin, LOW);
  delay(100);   
}
