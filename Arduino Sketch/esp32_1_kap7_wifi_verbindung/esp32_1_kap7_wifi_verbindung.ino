//
// ESP32 - Verbindung zu WLAN
// File: esp32_1_kap7_wifi_verbindung.ino

#include <WiFi.h>

// WLAN
#include "secrets.h"

void setup()
{
  // Serielle Schnittstelle
  Serial.begin(115200);
  // Verbindungsaufbau
  Serial.print("Verbinden mit WLAN: ");
  Serial.print(ssid);
  Serial.print(" ");

  // Wifi-Verbindung aktivieren
  WiFi.begin(ssid, password);

  // Verbinden...
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  // Verbindungsdaten
  Serial.println("");
  Serial.print("Verbunden mit: ");
  Serial.println(ssid);
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  // Ausgabe Verbindung
  Serial.println("");
  Serial.print("Verbunden mit: ");
  Serial.println(ssid);
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  delay(1000);
}