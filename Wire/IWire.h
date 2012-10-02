/*
  IWire.h - Common interface for TWI/I2C library for Arduino & Wiring
  Copyright (c) 2012 Korney Czukowski

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef WIRE_INTERFACE_H_
#define WIRE_INTERFACE_H_

#include <Arduino.h>

class IWire
{
	public:
		virtual void begin() = 0;
		virtual void begin(uint8_t) = 0;
		virtual void begin(int) = 0;
		virtual void beginTransmission(uint8_t) = 0;
		virtual void beginTransmission(int) = 0;
		virtual uint8_t endTransmission(void) = 0;
		virtual uint8_t endTransmission(uint8_t) = 0;
		virtual uint8_t requestFrom(uint8_t, uint8_t) = 0;
		virtual uint8_t requestFrom(uint8_t, uint8_t, uint8_t) = 0;
		virtual uint8_t requestFrom(int, int) = 0;
		virtual uint8_t requestFrom(int, int, int) = 0;
		virtual size_t write(uint8_t) = 0;
		virtual size_t write(const uint8_t *, size_t) = 0;
		virtual int available(void) = 0;
		virtual int read(void) = 0;
		virtual int peek(void) = 0;
		virtual void flush(void) = 0;
		// virtual void onReceive( void (*)(int) ) = 0;
		// virtual void onRequest( void (*)(void) ) = 0;
	protected:
		~IWire() {}
};

#endif /* WIRE_INTERFACE_H_ */