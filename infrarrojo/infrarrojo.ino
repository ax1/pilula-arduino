/**
   Ejemplo de mando a distancia por infrarrojos

   Borrar la librería IRRemoteRobot si existe porque colisiona con la que vamos a instalar
   (cerrar arduino, ir a la carpeta librerías y borrarla)

   Instalar la librería IRRemote

   Ayuda: http://www.pcbheaven.com/userpages/RC_Protocol_and_Modulation/

   PINSET:
   - GND a tierra
   - VCC a 5 Voltios
   - Signal a pin 6
*/

#include <IRremote.h>

int PIN_LECTURA = 6;
IRrecv irrecv(PIN_LECTURA);
decode_results mensaje;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // copiar los datos que llegan en la variable mensaje
  if (irrecv.decode(&mensaje)) {
    // mostrar todos los datos posibles;
    dump(&mensaje);
    irrecv.resume();
    delay (100);
    // ejecutar en función del botón del mando
    if (mensaje.value == 0xFF02FD) {
      Serial.println("¡¡¡¡¡¡¡¡¡¡¡¡ BOTON OK !!!!!!!!!!");
    }
  }
}


void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

/*
  void display(decode_results results) {
  Serial.println(results.value, HEX);
  Serial.println(results.address, HEX);
  Serial.println(results.value, HEX);
  Serial.println(results.decode_type);
  Serial.println(results.bits);
  Serial.println(results.rawlen);
  Serial.println(results.overflow);
  Serial.println("----------");
  }
*/


