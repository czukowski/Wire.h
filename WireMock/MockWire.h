/*
  MockWire.h - Mock class for TWI/I2C library for Arduino & Wiring
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

#ifndef MockWire_H_
#define MockWire_H_

#include <Arduino.h>
#include "IWire.h"
#include "TwoWire.h"

class MockWire : virtual public IWire
{
	private:
		uint8_t rxBuffer[BUFFER_LENGTH];
		uint8_t rxBufferIndex;
		uint8_t rxBufferLength;
		void addMethodCall(const char *methodName);
		void append(char *buffer, uint8_t& cursor, const char *data, int length);
	public:
		// Public properties with 'actual' values
		char methodCalls[BUFFER_LENGTH + 1];
		uint8_t methodCallsIndex;
		uint8_t initializedAddress;
		uint8_t transmitAddress;
		uint8_t transmitting;
		uint8_t requestedFromAddress;
		uint8_t requestedFromQuantity;
		uint8_t requestedFromSentStop;
		uint8_t endTransmissionSentStop;
		char writtenData[BUFFER_LENGTH + 1];
		uint8_t writtenQuantity;
		// Constructor
		MockWire();
		// Mocked methods
		void begin();
		void begin(uint8_t);
		void begin(int);
		void beginTransmission(uint8_t);
		void beginTransmission(int);
		uint8_t endTransmission(void);
		uint8_t endTransmission(uint8_t);
		uint8_t requestFrom(uint8_t, uint8_t);
		uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
		uint8_t requestFrom(int, int);
		uint8_t requestFrom(int, int, int);
		size_t write(uint8_t);
		size_t write(const uint8_t *, size_t);
		int available(void);
		int read(void);
		int peek(void);
		void flush(void);
		void onReceive( void (*)(int) );
		void onRequest( void (*)(void) );
};

#endif /* MockWire_H_ */