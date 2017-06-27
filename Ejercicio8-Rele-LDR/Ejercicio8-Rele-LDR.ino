int RelePin = 13; // Asigna RelePin al pin 13
int LDRPin = A0; // Asigna LDRPin al pin A0
int umbral = 100; //este valor lo obtenemos poniendo la mano sobre la LDR 


void setup() 
{
   pinMode(RelePin, OUTPUT); // Establece un pin digital como salida.  
   pinMode(LDRPin, INPUT); // Establece un pin analógico como entrada.  
}


 void loop() 
{
       if (analogRead(LDRPin)< umbral) { // compara el valor de la LDR con en que hemos asignado en la variable “umbral”
      digitalWrite(RelePin, HIGH);
 }
   else {
      digitalWrite(RelePin, LOW);
   }
}

