#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include <WakeOnLan.h>

const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

boolean wifiConnected = false;

WiFiUDP UDP;
/**
 * The Magic Packet needs to be sent as BROADCAST in the LAN
 */
IPAddress computer_ip(255,255,255,255); 

/**
 * The targets MAC address to send the packet to
 */
byte mac[] = { 0xFE, 0xBB, 0x34, 0xE5, 0x29, 0xFC };


boolean connectWifi(); //empty methods defined here, for declaration see lower.
void sendWOL();

void setup() {
  // Initialise Serial connection
  Serial.begin(115200);

  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  UDP.begin(9); //start UDP client, not sure if really necessary.
}

void loop()
{
  if (wifiConnected) {
    Serial.println("Sending WOL Packet...");

    WakeOnLan::sendWOL(computer_ip, UDP, mac, sizeof mac);
    delay(4000); //sending WOL packets every 4th second.
  }
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi() {
  boolean state = true;
  int i = 0;
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false;
      break;
    }
    i++;
  }
  if (state) {
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  return state;
}
