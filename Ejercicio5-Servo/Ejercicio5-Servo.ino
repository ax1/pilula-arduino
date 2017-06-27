#include <Servo.h>
//Creamos la variable llamada "myservo", y declaramos una variable como integer dándole valor inicial "0"
Servo myservo;
int pos = 0;    // variable to store the servo position
//En el setup asignamos la variable "myservo" al pin (9) del arduino
void setup() {
  myservo.attach(9);

}
//En el loop()  moveremos el servo, grado a grado a la velocidad indicada en el "delay". Una vez alcanzados los 180º invertimos el sentido de giro.
void loop() {
  for (pos = 0; pos <= 180; pos += 1) {  // Le damos valor "0" a la variable pos; verificamos que es igual o menor que 180º y le sumamos "1" a "pos".
    myservo.write(pos);              // indicamos al servo que se mueva a pos.
    delay(15);                       // esperamos 15 ms a que el servo vaya a su nueva posición.

  }
  for (pos = 180; pos >= 0; pos -= 1) { // Le damos valor "180" a la variable pos; verificamos que es igual o mayor que 180º y le restamos "1" a "pos".

    myservo.write(pos);              // le indicamos al servo que se mueva a pos.

    delay(15);                       // esperamos 15 ms a que el servo vaya a su nueva posición.
  }
}

