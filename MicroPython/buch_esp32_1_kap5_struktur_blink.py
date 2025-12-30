# ESP32 MicroPython - Struktur Blink
# Datei: buch_esp32_1_kap5_struktur_blink.py


# Bibliothek
from machine import Pin
from time import sleep


# Variablen
led = Pin(2, Pin.OUT)

# Funktionen

# Loop
while True:
    # LED Ein
    led.on()
    # Warten 0.5 Sekunden
    sleep(0.5)
    # LED Aus
    led.off()
    # Warten 0.5 Sekunden
    sleep(0.5)
