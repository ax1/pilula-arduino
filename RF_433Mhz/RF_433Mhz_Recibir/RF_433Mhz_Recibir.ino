
/**
   Radio de 433Mhz para RECIBIR datos inalámbricamente
   Instalar librería "RadioHead"
   3 pines:
    - GND a tierra
    - VCC a 5 voltios
    - cualquiera de los pines del medio para recibir (en este caso PIN 4, ver debajo)
*/

#include <RH_ASK.h>
#include <SPI.h> // necesario para  la librería rh_ask

// configurar la radio
RH_ASK radio(2000, 4, 5); // velocidad de transmisión, pin de lectura, pin de escritura

void setup(){
    Serial.begin(9600);
  if (!radio.init()) Serial.println("error en la radio");
}

void loop()
{   
    char mensaje[12];
    unsigned int longitud = sizeof(mensaje);
    bool hayMensaje = radio.recv(mensaje, longitud); // el & es necesario !!!
    if (hayMensaje) { 
      Serial.println((char*)mensaje);         
    }
}
