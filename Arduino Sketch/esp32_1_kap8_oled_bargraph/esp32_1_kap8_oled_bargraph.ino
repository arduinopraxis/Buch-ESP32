//
// ESP32 - OLED I2C Bargraph (128x64)
// Datei: esp32_1_kap8_oled_bargraph.ino

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Display
// Breite in Pixel
#define SCREEN_WIDTH 128
// Höhe in Pixel
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Messspannung
int voltage=0;
const int AnalogPin(A0);

void setup()   
{
  // Initialisierung OLED an I2C Adresse 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);

  // Buffer löschen
  display.clearDisplay();

  // Ausgabe Startbildschirm
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("OLED...");
  display.display();
  delay(2000);
  display.clearDisplay();
}


void loop() 
{
  // Spannung an A0 messen oder Messsignal von externem Sensor
  voltage=analogRead(AnalogPin);
  voltage=1000;
  
  // Ausgabe Text
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(voltage);
  display.display();

  // Bargraph
  // Rechteck zeichnen
  display.drawRect(0,32,1023/10, 4, WHITE);
  // Balken füllen gemäss Messsignal
  display.fillRect(0,32, voltage/10, 4, WHITE);
  // Display aktualisieren
  display.display();
  delay(1000);
  // Display löschen
  display.clearDisplay();
}
