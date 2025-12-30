//
// ESP32 - Webserver - Anzeige Analoge Eingänge
// File: esp32_1_kap7_wifi_webserver_analog.ino

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// WLAN
#include "secrets.h"

// Webserver an Port 80
AsyncWebServer server(80);

// Analoge Eingänge
const int AnalogPin1 = A0;
const int AnalogPin2 = A1;

// HTML-Seite
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP32 - Analoge Eingänge</title>
  </head>
<body>
  <h2>ESP32 - Analoge Eingänge</h2>
  <table>
    <thead><tr><th>Pin</th><th>Wert</th></tr></thead>
    <tbody id="data"></tbody>
  </table>

  <script>
    async function getData() {
      const response = await fetch("/analog");
      const data = await response.json();
      let html = "";
      for (let i = 0; i < data.values.length; i++) {
        html += `<tr><td>GPIO ${data.values[i].pin}</td><td>${data.values[i].value}</td></tr>`;
      }
      document.getElementById("data").innerHTML = html;
    }
    setInterval(getData, 2000);
    getData();
  </script>
</body>
</html>
)rawliteral";


void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);

  // Analoge Pins konfigurieren
  pinMode(AnalogPin1, INPUT);
  pinMode(AnalogPin2, INPUT);
  

  // WLAN verbinden
  WiFi.begin(ssid, password);
  Serial.print("Verbinden mit WLAN...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Verbunden...");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  // Route: Startseite
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", htmlPage);
  });

  // Route: JSON mit Analogwerten
  server.on("/analog", HTTP_GET, [](AsyncWebServerRequest *request){
    String json = "{\"values\":[";
    int val1 = analogRead(AnalogPin1);
    int val2 = analogRead(AnalogPin2);
      json += "{\"pin\":" + String(AnalogPin1) + ",\"value\":" + String(val1) + "}";
      json += ",";
      json += "{\"pin\":" + String(AnalogPin2) + ",\"value\":" + String(val2) + "}";
       json += "]}";
    request->send(200, "application/json", json);
  });

  // Server starten
  server.begin();
  Serial.println("Asynchroner Webserver...");
}

void loop() {
  // Nichts nötig – läuft asynchron
}
