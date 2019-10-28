#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid     = "ssid";
const char* password = "pass";
const char* ipd = "192.168.43.123";
const int port = 33333;
 
void setup() {
 
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  //WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(2000);
  
}

WiFiUDP Udp;

unsigned long tim=micros();
unsigned long tic=micros();
int packageCount = 0;
char charBuf[755]; 
String stringOne = "";
int j=10000;

void loop() {

      j++;
      if (j<12001) { // testing with 2000 packets
      Serial.println(j);
      stringOne="1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890";
      stringOne=stringOne+"1234567890123456789012345678901234567890"; // 750 Bytes string
      stringOne=stringOne+"1234567890123456789012345"+String(j);
      stringOne.toCharArray(charBuf,751);
      
      Udp.beginPacket(ipd, port);
      Udp.write(charBuf);
      Udp.endPacket();  
      
      //delay(3); // for a 20Mbps WiFi network sending directly to the a Linode 4096 Node.js server.
      delay(90); // for a 2Mbps mobile hotspot sending to Core i3 Node.js server.
      
      } 
 
}

