/**
   https://play.google.com/store/apps/details?id=appinventor.ai_el_profe_garcia.Arduino_Control_Car
   BTO4 device is a slave device -> only for receiving data
   PIN (bluetooth) = 1234
*/

#include <SoftwareSerial.h>
 
int PIN_RX = 10; // arduino RX = radio TX
int PIN_TX = 11;// arduino TX = radio RX
SoftwareSerial softwareSerial(PIN_RX, PIN_TX);

void setup() {
  Serial.begin(9600); // This is the serial to communicate with the PC
  softwareSerial.begin(9600); // This is the serial to communicate with the radio
}

void loop() {
  if (softwareSerial.available()) {
    int action = softwareSerial.read();
    Serial.write(action);
    execute(action);
  }
}

void execute(int action) {
  switch (action) {
    case 'f' :
      Serial.println( "ON button");
      break;
    default:
      ;
  }
}

