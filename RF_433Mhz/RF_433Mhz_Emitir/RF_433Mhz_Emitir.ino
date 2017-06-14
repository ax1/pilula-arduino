/**
   Radio de 433Mhz para TRANSMITIR datos inalámbricamente
   Instalar librería "RadioHead"
   3 pines:
    - GND a tierra
    - VCC a 5 voltios
    - ATAD al pin de tranmisión (en este caso PIN 5, ver debajo)
*/

#include <RH_ASK.h>
#include <SPI.h> // necesario para  la librería rh_ask
. 
// configurar la radio
RH_ASK radio(2000, 4, 5); // velocidad de transmisión, pin de lectura, pin de escritura

void setup() {
  Serial.begin(9600);
  if (!radio.init()) Serial.println("error en la radio");
}

void loop() {
  char mensaje[] = "Enviando 433"; //20 caracteres máximo, ver código del receptor
  radio.send(mensaje, strlen(mensaje));
  radio.waitPacketSent();
  Serial.println("paquete enviado");
  delay(1000);
}

