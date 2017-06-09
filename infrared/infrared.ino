/**
   Infrared receiver example

    Depending on arduino IDE the ir library loaded by default is IRRemoteRobot and it has an error
    Close arduino, remove library in 'libraries' folder and install a proper IRRemote (use library manager)
    general doc http://www.pcbheaven.com/userpages/RC_Protocol_and_Modulation/
*/

#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    //display(results);
    dump(&results);
    irrecv.resume();
    delay (100);
    if (results.value == 0xFF02FD) {
      Serial.println("¡¡¡¡¡¡¡¡¡¡¡¡ OK BUTTON WAS PRESSED !!!!!!!!!!");
    }
  }
}

void display(decode_results results) {
  Serial.println(results.value, HEX);
  Serial.println(results.address, HEX);
  Serial.println(results.value, HEX);
  Serial.println(results.decode_type);
  Serial.println(results.bits);
  Serial.println(results.rawlen);
  Serial.println(results.overflow);
  Serial.println("----------");
}

void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

