# ESP32 MicroPython - Analog Input
# Datei: buch_esp32_1_kap5_analog_in.py

# Bibliotheken
from machine import ADC, Pin
import time

# Variablen
# Analoger Eingangspin an GPIO2
adc = ADC(Pin(2))

while True:
    # Analoger Eingang einlesen
    AnalogVal = adc.read()
    # Ausgabe Analogwert
    print("Wert:", AnalogVal)
    time.sleep(1)