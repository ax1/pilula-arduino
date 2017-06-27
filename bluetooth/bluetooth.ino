/**
   Recibir datos por BLUETOOTH
   Instalar programa en el móvil para enviar los datos
   https://play.google.com/store/apps/details?id=appinventor.ai_el_profe_garcia.Arduino_Control_Car
   el módulo BTO4  es un buetooth de tipo esclavo -> sólo recibirá datos
   PIN (contraseña del bluetooth) = 1234

   Conexiones:
   - GND a tierra
   - VCC a 5 voltios (aunque ponga 3.3V no pasa nada porque la radio sólo la vamos a usar como receptor)
   - RXD al pin de transmision que configuremos en arduino (no es necesario conectarlo para éste ejercicio)
   - TXD al pin de recepción que configuremos en arduino

*/

#include <SoftwareSerial.h>

int PIN_RX = 10; // arduino RX = radio TX
int PIN_TX = 11;// arduino TX = radio RX
SoftwareSerial softwareSerial(PIN_RX, PIN_TX);

void setup() {
  Serial.begin(9600);
  softwareSerial.begin(9600); // Es un serial adicional para poder comunicarnos con la radio
}

void loop() {
  if (softwareSerial.available()) {
    int comando = softwareSerial.read();
    Serial.write(comando);
    ejecutar(comando);
  }
}

void ejecutar(int comando) {
  switch (comando) {
    case 'f' :
      Serial.println( "botón ON");
      break;
    default:
      ;
  }
}

