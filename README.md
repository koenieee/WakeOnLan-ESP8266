# WakeOnLan-ESP8266
Very small and simple library to use the ESP8266 for sending magic packets to an enabled Wake On LAN device.

# Example

Use the library with the (only) function like this:

```c
IPAddress computer_ip(255, 255, 255, 255); \\ DON'T change this, this will cause magic packet to be sent as BROADCAST

byte mac[] = { 0xFE, 0xBB, 0x34, 0xE5, 0x29, 0xFC }; \\ CHANGE this to the machine's mac address

WakeOnLan::sendWOL(computer_ip, UDP, mac, sizeof mac);


```

Or just look into the file: examples/WakeOnLan-ESP8266/WakeOnLan-ESP8266.ino 
To view a full working example.

# Installation

Copy the library into the folder: 

C:\Program Files (x86)\Arduino\libraries (for x64 systems)

C:\Program Files\Arduino\libraries (for x32 systems)

Note: This library only works using the Arduino IDE v1.0+
