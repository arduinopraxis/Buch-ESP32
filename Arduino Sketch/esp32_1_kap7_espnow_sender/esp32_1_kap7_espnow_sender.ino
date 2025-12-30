//
// ESP32 - ESP-Now Sender
// Datei: esp32_1_kap7_espnow_sender.ino

#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>


// MAC Adresse von Empfänger EC:DA:3B:35:F0:9C
uint8_t receiverAddress[] = {0xEC, 0xDA, 0x3B, 0x35, 0xF0, 0x9C};

// Interne Sensor ID
#define NodeID 11;

// Sender Datenstruktur
typedef struct Payload {
  int ID;
  int sensor1;
  int sensor2;
  int vbatt;
};

// Datenstruktur erstellen
Payload SensorData;

// Timer (30 Sekunden)
unsigned long lastTime = 0;  
unsigned long timerDelay = 30000;

// Peer-Info
esp_now_peer_info_t peerInfo;

// Callback Datenversand
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Packet Versand-Status: ");
  if (sendStatus == 0){
    Serial.println("Versand erfolgreich...");
  }
  else{
    Serial.println("Fehler Versand!");
  }
}
 
void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);
 
  // Wifi im Station-Mode
  WiFi.mode(WIFI_STA);

  // Initialisierung ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Fehler Initialisierung ESP-NOW");
    return;
  }

  // Callback registrieren
  esp_now_register_send_cb((esp_now_send_cb_t)OnDataSent);

  // Peer (Empfänger) hinzufügen
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;    // gleicher Kanal wie Empfänger
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Fehler beim Hinzufügen des Peers");
  }
 }
 
void loop() 
{
  // Timer für Datenversand
  if ((millis() - lastTime) > timerDelay) {
    // Sensor Werte
    SensorData.ID = NodeID;
    SensorData.sensor1 = 1111;
    SensorData.sensor2 = 2222;
    SensorData.vbatt = 3322;

    // Daten senden
    esp_err_t sendresult = esp_now_send(receiverAddress, (uint8_t *) &SensorData, sizeof(SensorData));

     if (sendresult == ESP_OK) {
    Serial.println("Erfolgreich versendet...");
    }
    else
    {
    Serial.println("Fehler beim Versenden...");
  }

    lastTime = millis();
  }
}