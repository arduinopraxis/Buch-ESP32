//
// ESP32 - ESP-NOW - MAC-Adresse ermitteln
// File: esp32_1_kap7_esp-now_mac.ino

#include <WiFi.h>
#include <esp_wifi.h>

void setup() 
{
  // Serielle Schnittstelle
  Serial.begin(115200);

  // Wi-Fi im Station-Mode
  WiFi.mode(WIFI_STA);

  // MAC-Adresse abrufen (String)
  String mymacStr = WiFi.macAddress();
  Serial.print("MAC-Adresse: ");
  Serial.println(mymacStr);

  // Ausgabe MAC-Adresse als Array
  uint8_t mac[6];
  esp_err_t result = esp_wifi_get_mac(WIFI_IF_STA, mac);
  if (result == ESP_OK) {
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  mac[0], mac[1], mac[2],
                  mac[3], mac[4], mac[5]);
  } 
  else 
  {
    Serial.println("Fehler beim Lesen der MAC-Adresse");
  }
}

void loop() 
{
  // keine Aktion
}
