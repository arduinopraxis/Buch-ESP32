//
// ESP32 - Webserver 
// File: esp32_1_kap7_wifi_webserver_led_out.ino

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// WLAN
#include "secrets.h"

// Server auf Port 80
AsyncWebServer server(80);

// HTML-Seite
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP32 Async Webserver</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; text-align: center; margin-top: 40px; }
    h1 { color: #0078D7; }
    button { padding: 10px 20px; font-size: 16px; }
  </style>
</head>
<body>
  <h1>ESP32 Asynchroner Webserver</h1>
  <p><a href="/led/on"><button>LED EIN</button></a></p>
  <p><a href="/led/off"><button>LED AUS</button></a></p>
</body>
</html>
)rawliteral";

// LED-Pin
const int ledPin = 2;

// Setup
void setup() 
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // WLAN verbinden
  WiFi.begin(ssid, password);
  Serial.print("Verbinde mit WLAN");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nVerbunden!");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  // Route: Startseite
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // LED EIN
  server.on("/led/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, HIGH);
    request->send(200, "text/plain", "LED ist jetzt EIN");
  });

  // LED AUS
  server.on("/led/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, LOW);
    request->send(200, "text/plain", "LED ist jetzt AUS");
  });

  // Server starten
  server.begin();
  Serial.println("Asynchroner Webserver gestartet!");
}

void loop() {
  // nichts nötig – alles läuft asynchron
}
