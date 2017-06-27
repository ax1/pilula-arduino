#include <Servo.h>  // Carga la librería Servo.h que contiene métodos para trabajar con servos
Servo myservo;   // Crea un objeto servo "myservo"
int potpin = A0;  // Asigna el pin analógico A0 para conectar el potenciómetro
int val;        // variable para leer el valor del potenciometro

void setup()
{
myservo.attach(9);  // asocia el servo al pin 9
}

void loop()
{
val = analogRead(potpin);   // lee el valor del potenciómetro (valor entre 0 y 1023)
val = map(val, 0, 1023, 0, 180);   // escala o mapea el valor de val (valor entre 0 y 180)
myservo.write(val);        // envia a "myservo" la posición de "val" escalada entre 0 y 180.
delay(15);                 // espera 15ms a que el servo se posicione
}

