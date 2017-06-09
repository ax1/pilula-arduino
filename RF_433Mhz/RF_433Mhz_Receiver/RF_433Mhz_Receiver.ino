


#define PIN_RF  A0
boolean STATUS = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  unsigned int data = analogRead(PIN_RF);
  if (500> data > 700) {
    Serial.print(data, DEC);
    Serial.print(" ");
    STATUS = LOW; 
    digitalWrite(LED_BUILTIN, STATUS);
  }else if (20 < data <100 ) {
    Serial.print(data);
    Serial.print(" ");
    STATUS = HIGH;
    digitalWrite(LED_BUILTIN, STATUS);
  }
}

void toggle() {
  STATUS = !STATUS;
}

