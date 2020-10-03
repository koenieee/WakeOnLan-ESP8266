/*************************************************************************
Title:    Wake on LAN library for the ESP8266
Authors:  Koen, Utrecht, Netherlands
File:     WakeOnLan.h
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

#ifndef wakeonloan_h
#define wakeonloan_h

#include <SPI.h>
#include <WiFiUdp.h>


class WakeOnLan {

	public:		
		/**
		* Sending magic packet to specified IP and MAC address.
		* @param addr The IP address for the WOL target
		* @param udp The UDP client use to send the packet with.
		* @param mac The MAC address in a array of six bytes
		* @param size_of_mac The size of the mac address array, mostly 6, because of 6 bytes.
		*/
		static void sendWOL(IPAddress addr, WiFiUDP udp, byte * mac,  size_t size_of_mac);
		
		
};

#endif
