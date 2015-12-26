# WakeOnLan-ESP8266
Very small and simple library to use the ESP8266 for sending magic packets to an enabled Wake On LAN device.

# Example

Use the library with the (only) function like this:

```c
byte mac[] = { 0xFR, 0xBB, 0x34, 0xE5, 0x29, 0xFC };

IPAddress computer_ip(192, 168, 178, 26); 

WakeOnLan::sendWOL(computer_ip, UDP, mac, sizeof mac);


```

Or just look into the file: examples/WakeOnLan-ESP8266/WakeOnLan-ESP8266.ino 
To view a full working example.

# Installation

Copy the library into the folder: 

C:\Program Files (x86)\Arduino\libraries (for x64 systems)

C:\Program Files\Arduino\libraries (for x32 systems)

Note: This library only works using the Arduino IDE v1.0+
