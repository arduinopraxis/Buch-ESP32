//
// ESP32 - Webserver - Anzeige Analoge Eingänge
// File: esp32_1_kap7_wifi_webserver_analog_simple.ino

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
// WLAN
#include "secrets.h"

// Webserver-Objekt (Port 80)
AsyncWebServer server(80);
// Analoge Eingang
const int AnalogPin1 = A0;

const char indexHtml[] PROGMEM = R"rawliteral(
<!doctype html>
<html>
  <head>
    <meta charset="utf-8"/>
    <title>ESP32 - Analogeingang</title>
  </head>
  <body>
    <h1>ESP32 - Analogeingang</h1>
    <div>Eingang A0:</div>
    <div class="value" id="val">--</div>
    <script>
      async function poll(){
        try{
          const r = await fetch('/analog');
          const j = await r.json();
          document.getElementById('val').textContent = j.value;
        }catch(e){
          document.getElementById('val').textContent = 'ERR';
        }
      }
      setInterval(poll, 1000);
      poll();
    </script>
  </body>
</html>
)rawliteral";

void setup()
{
  Serial.begin(115200);
  // Analogeingang 12 Bit
  analogReadResolution(12);
  pinMode(AnalogPin1, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print('.');
    delay(300);
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Startseite
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", indexHtml);
  });

  // Analog Endpunkt - Rückgabewert JSON
  server.on("/analog", HTTP_GET, [](AsyncWebServerRequest *request){
    int aWert1 = analogRead(AnalogPin1);
    String json = "{\"value\":" + String(aWert1) + "}";
    request->send(200, "application/json", json);
  });

  server.begin();
  Serial.println("Webserver gestartet");
}

void loop()
{
  // keine weiteren Anweisungen notwendig
}
