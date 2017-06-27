/*
 BLINK
 Enciende un LED durante un segundo, lo apaga durante otro segundo, repetidamente. 
 */
//Configuramos el pin 13 como una Salida (OUPUT)
void setup() { 
pinMode(13, OUTPUT); // Establece un pin digital como salida.  El Pin 13 tiene un LED conectado a el.
}
//Ejecutamos el contenido loop() continuamente 
void loop() {
digitalWrite(13, HIGH);   // Pone el pin 13 a nivel alto (5v). Enciende el LED
delay(1000);              // espera un segundo (1000 milisegundos)
digitalWrite(13, LOW);    // Pone el pin 13 a nivel bajo (0v). apaga el LED
delay(1000);              // espera un segundo (1000 milisegundos)
}

