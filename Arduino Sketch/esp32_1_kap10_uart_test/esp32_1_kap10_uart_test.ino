// ESP32 - Serial Test
// Datei: esp32_1_kap10_uart_test.ino

#include <HardwareSerial.h>

// UART2 verwenden für GPS
HardwareSerial SerialGPS(2);

void setup() 
{
  // Serielle Schnittstelle für Ausgabe
  Serial.begin(115200);
  // UART 2
  // RX=16, TX=17
  SerialGPS.begin(SerialGPS, SERIAL_8N1, 16, 17);  
  Serial.println("UART2 gestartet...");
}

void loop() 
{
  // Falls Daten empfangen
  if (SerialGPS.available()) {
    // Daten anzeigen
    Serial.write(SerialGPS.read());  
  }
}
