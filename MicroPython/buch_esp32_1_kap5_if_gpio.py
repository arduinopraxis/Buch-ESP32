# ESP32 MicroPython - GPIO
# Datei: buch_esp32_1_kap5_if_gpio.py

from machine import Pin
from time import sleep

# Taster an Pin 2
taster = Pin(2, Pin.IN)
# LED an Ausgang 4
led = Pin(4, Pin.OUT)


while True:
    if taster.value() == 1:
        # Ausgang EIN
        led.value(1)
        print("EIN")
    else:
        # Ausgang AUS
        led.value(0)
        print("AUS")
    sleep(1)
    
        