
int PIN_RF = 4;
 
void setup() {
  pinMode(PIN_RF, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() {
  sendSignal(LOW);
  delay(1000);
  sendSignal(HIGH);
   delay(5000);
}

void sendSignal(boolean active) {
  digitalWrite(PIN_RF, active);
  digitalWrite(LED_BUILTIN, active);
}

