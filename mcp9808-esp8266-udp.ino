#include <Wire.h>
#include "Adafruit_MCP9808.h"
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "SSID";
const char* password = "PASS";
const char* ipd = "192.168.43.141";
const int port = 33333;
WiFiUDP Udp;
char buff[30]; 
String message = "";

void setup() 
{
	Serial.begin(115200);
	Serial.println("MCP9808 demo");
	if (!tempsensor.begin()) {  
		Serial.println("Couldn't find MCP9808!");
		while (1);
	}
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);
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

void loop() {
	float c = tempsensor.readTempC();
	message="B,"+String(micros())+","+String(c)+"*C\t";
	message.toCharArray(buff,30);
	Udp.beginPacket(ipd, port);
	Udp.write(buff);
	Udp.endPacket();  
	Serial.print(c);
	Serial.println();
	delay(8);
}
