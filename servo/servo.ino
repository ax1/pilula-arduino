#include <Servo.h>

Servo servo;
int PIN_SERVO = 9;
int TRIGGER = 4;
int counter = 0;


void setup() {
  Serial.begin(9600);
  servo.attach(PIN_SERVO);
  // gentleStart(); this does not work because the servo.read() is executed after servo has started.
}


void loop() {
  int period = 20;
  int pos = 0;
  if (counter >= TRIGGER && counter <= TRIGGER * 4) period = 1;
  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(period);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(period);
  }
  counter++;
}


//void gentleStart() {
//    for (pos = servo.read(); ; pos >= 0; pos -= 1) {
//      servo.write(pos);
//      delay(200);
//  }
//}

