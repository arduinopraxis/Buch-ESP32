//
// ESP32 - Webserver 
// File: esp32_1_kap7_wifi_webserver_simple.ino

#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// WLAN
#include "secrets.h"

// Webserver-Objekt
AsyncWebServer server(80);

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);
  // Wifi starten
  WiFi.begin(ssid, password);
  // Verbindungsaufbau
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

   // Ausgabe
  Serial.println("");
  Serial.println("WiFi verbunden...");
  Serial.print("IP Adresse: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hallo ESP32- asynchroner Webserver!");
  });

  server.begin();
}

void loop() 
{
  // Anweisungen
}
