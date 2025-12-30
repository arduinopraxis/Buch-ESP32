//
// ESP32 - ESP-NOW Empfänger
// Datei: esp32_1_kap7_espnow_receiver.ino

#include <WiFi.h>
#include <esp_now.h>

// Struktur - empfangene Daten
typedef struct Payload {
  int ID;
  int sensor1;
  int sensor2;
  int vbatt;
} struct_message;

// Datenstruktur erstellen
Payload RecData;


// Empfangene Daten verarbeiten
void OnDataRecv(uint8_t * mac_addr, uint8_t *incomingData, uint8_t len) {
  char macStr[18];
  //Serial.print("Daten empfangen von: ");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  //Serial.println(macStr);
  memcpy(&RecData, incomingData, sizeof(RecData));
   // Ausgabe kommasepariert
  // Format: SEN11,1111,2222,3322!
  Serial.print("SEN");
  Serial.print(RecData.ID);
  Serial.print(",");
  Serial.print(RecData.sensor1);
  Serial.print(",");
  Serial.print(RecData.sensor2);
  Serial.print(",");
  Serial.print(RecData.vbatt);
  Serial.println("!");
}
 
void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);
  
  // Wifi im Station-Mode
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Initialisierung ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Fehler bei der Initialisierung von ESP-NOW");
    return;
  }
  
  // Registrierung für Empfang
  esp_now_register_recv_cb((esp_now_recv_cb_t)OnDataRecv);
 }

void loop()
{
  // Eigene Anweisungen
 }