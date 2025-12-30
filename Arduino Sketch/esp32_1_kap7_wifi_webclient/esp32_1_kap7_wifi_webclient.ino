//
// ESP32 - Webclient
// File: esp32_1_kap7_wifi_webclient.ino

#include <WiFi.h>
// WLAN
#include "secrets.h"

const char *host = "projekte.555circuitslab.com";
const char *url = "/esp32seite.htm";

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
}

void loop() 
{
  delay(5000);

  Serial.print("Verbinden mit...");
  Serial.println(host);

  // TCP-Verbindung
  NetworkClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  Serial.print("Aufruf URL: ");
  Serial.println(url);

  // Client-Request an Server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println("Client Timeout...");
      client.stop();
      return;
    }
  }

  // Response vom Server
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("Verbindung schliessen");
}
