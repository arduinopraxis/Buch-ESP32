# ESP32 MicroPython - UART
# Datei: buch_esp32_1_kap5_gpio_uart.py

#Bibliotheken
from machine import UART
from time import sleep


# Variablen
# UART1
uart1 = UART(1, baudrate=9600, tx=21, rx=20)


while True:
    # Serielle Ausgabe
    uart1.write('Hallo ESP32') 
    sleep(1)
    
        