# ESP32 MicroPython - Umrechung Celsius/Fahrenheit-Fahrenheit/Celsius
# Datei: buch_esp32_1_kap5_umrechnung_temp.py

# Bibliothek
import time

# Variablen

# Funktionen
def ConvFtoC(tempF):
    tempC=((tempF-32)/1.8)
    return tempC

def ConvCtoF(tempC):
    tempF=(tempC*1.8)+32
    return tempF
    
# Loop
while True:
    celsius=ConvFtoC(98)
    print("Celsius:")
    print(celsius)
    time.sleep(1)
    fahrenheit=ConvCtoF(12)
    print("Fahrenheit:")
    print(fahrenheit)
    time.sleep(1)
