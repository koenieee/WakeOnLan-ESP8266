/*************************************************************************
Title:    Wake on LAN library for the ESP8266
Authors:  Koen, Utrecht, Netherlands
File:     WakeOnLan.cpp
License:  GNU General Public License v3

LICENSE:
    Copyright (C) 2015 Koen
    
    The latest source can be obtained from ISE's Github repository here:


    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License along
    with this program. If not, see http://www.gnu.org/licenses/
    
*************************************************************************/
#include "WakeOnLan.h"

void WakeOnLan::sendWOL(IPAddress addr, WiFiUDP udp, byte * mac,  size_t size_of_mac) {

    byte preamble[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    byte i;

    udp.beginPacket(addr, 9); //sending packet at 9, 
	
    udp.write(preamble, sizeof preamble);
    
    for (i = 0; i < 16; i++)
	{
        udp.write(mac, size_of_mac);
	}
    udp.endPacket();
}
