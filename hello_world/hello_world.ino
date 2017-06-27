
/**
 * Blink a led. 
 * No extra gadgets, just plug the arduino board.
 */
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1500);                      
}
