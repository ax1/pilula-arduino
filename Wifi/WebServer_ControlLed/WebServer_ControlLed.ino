

#include "WiFiEsp.h"

char ssid[] = "TwimEsp";         // your network SSID (name)
char pass[] = "12345678";        // your network password

int ledPin = 8; //Lo conectamos a D7
int status = WL_IDLE_STATUS;     // the Wifi radio's status


#include "SoftwareSerial.h"
SoftwareSerial Serial3(6, 7); // RX, 

WiFiEspServer server(80);

void setup() {
 Serial.begin(9600);
 Serial3.begin(9600);    // initialize serial for ESP module
 delay(10);

 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
  
  WiFi.init(&Serial3);    // initialize ESP module
  
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true); // don't continue
  }
  Serial.print("Attempting to start AP ");
  Serial.println(ssid);
  
  // uncomment these two lines if you want to set the IP address of the AP
  //IPAddress localIp(192, 168, 4, 1);
  //WiFi.configAP(localIp);
  
  // start access point
  status = WiFi.beginAP(ssid, 10, pass, ENC_TYPE_WPA2_PSK);

  Serial.println("AP started");
  printWifiStatus();
  

  // start the web server on port 80
  server.begin();
  Serial.println("Server started");
}

void loop() {

 WiFiEspClient client = server.available();
 if (!client) {
   return;
 }


 Serial.println("new client");
 while(!client.available()){
   delay(1);
 }

 String request = client.readStringUntil('\r');
 client.flush();


 int value = digitalRead(ledPin);
 if (request.indexOf("/LED=ON") != -1)  {
   digitalWrite(ledPin, HIGH);
   value = HIGH;
 }
 if (request.indexOf("/LED=OFF") != -1)  {
   digitalWrite(ledPin, LOW);
   value = LOW;
 }


 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");

 client.print("El led esta ahora: ");

 if(value == HIGH) {
   client.print("Encendido");
   client.println("<br><br>");
   client.println("<a href=\"/LED=OFF\"\"><button>Apagar</button></a><br />");  
 } else {
   client.print("Apagado");
client.println("<br><br>");
 client.println("<a href=\"/LED=ON\"\"><button>Encender</button></a>");
 }
 client.println("</html>");

 delay(1);

}



void printWifiStatus()
{
  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in the browser
  Serial.println();
  Serial.print("To see the page, connect to ");
  Serial.print(ssid);
  Serial.print(" and open a browser to http://");
  Serial.println(ip);
  Serial.println();
}

