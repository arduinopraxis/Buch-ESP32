//
// ESP32 - MQTT PubSubclient
// Datei: esp32_1_kap7_mqtt_pubsub.ino


#include <WiFi.h>
#include <PubSubClient.h>

// WLAN
#include "secrets.h"

// MQTT-Broker
const char* mqtt_server = "192.168.1.44";
const char* mqttTopicPub = "ESP32/Temp";
const char* mqttTopicSub = "ESP32/Light";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() 
{
  delay(10);
  
  Serial.println();
  Serial.print("Verbindungsaufbau mit ");
  Serial.println(ssid);
  // WLAN
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Wifi IP-Adresse
  Serial.println("");
  Serial.println("WiFi verbunden..");
  Serial.println("IP-Adresse: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Daten vom Broker
  String msg;
  Serial.print("Nachricht: von [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    msg += (char)payload[i];
  }
  Serial.println();

  // Weiterverarbeitung von empfangenen Nachrichten
  if (String(topic) == "ESP32/Light") {
    if (msg == "ON") Serial.println("Relais EIN");
    if (msg == "OFF") Serial.println("Relais AUS");
  }
}

void reconnect() {
  // Reconnect
  while (!client.connected()) {
    Serial.print("MQTT Verbindung...");
    // Client ID
    String clientId="ESP32Client";
    // Verbindungsaufbau
    if (client.connect(clientId.c_str())) {
      Serial.println("verbunden");
      // Topic abonnieren
      client.subscribe(mqttTopicSub);
      } 
      else 
      {
      Serial.print("Fehler...=");
      delay(5000);
    }
  }
}

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);
  // Wifi
  setup_wifi();
  // MQTT
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() 
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Alle 20 Sekunden
  unsigned long now = millis();
  if (now - lastMsg > 20000) {
    lastMsg = now;
    String msgPub = "23.55 C";
    client.publish(mqttTopicPub, msgPub.c_str());
  }
}
