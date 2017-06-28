int LEDPin = 11;
int LDRPin = A0;
int umbral = 100; //este valor lo obtenemos poniendo la mano sobre la LDR 

void setup() 
{
   pinMode(LEDPin, OUTPUT);
   pinMode(LDRPin, INPUT);
}

 void loop() 
{
       if (analogRead(LDRPin)< umbral) {
      digitalWrite(LEDPin, HIGH);
 }
   else {
      digitalWrite(LEDPin, LOW);
   }
}


