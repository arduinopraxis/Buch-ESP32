# ESP32 MicroPython - Blink
# Datei: buch_esp32_1_kap3_blink.py


# Bibliothek
from machine import Pin
from time import sleep

# Pin 2 als Ausgang
led = Pin(2, Pin.OUT)

#Loop
while True:
    # LED Ein
    led.on()
    # Warten 0.5 Sekunden
    sleep(0.5)
    # LED Aus
    led.off()
    # Warten 0.5 Sekunden
    sleep(0.5)
