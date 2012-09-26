/*
  MockWire.h - Mock class implementation
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

extern "C" {
	#include <stdlib.h>
	#include <string.h>
	#include <inttypes.h>
}

#include "IWire.h"
#include "TwoWire.h"
#include "MockWire.h"

// Begin method
void MockWire::begin(uint8_t address)
{
	addMethodCall("begin");
	initializedAddress = address;
}
void MockWire::begin(int address)
{
	begin( (uint8_t) address);
}
void MockWire::begin(void)
{
	begin(0);
}

// Begin Transmission method
void MockWire::beginTransmission(uint8_t address)
{
	addMethodCall("beginTransmission");
	transmitting = 1;
	transmitAddress = address;
}
void MockWire::beginTransmission(int address)
{
	beginTransmission( (uint8_t) address);
}

// End Transmission method
uint8_t MockWire::endTransmission(uint8_t sendStop)
{
	transmitting = 0;
	addMethodCall("endTransmission");
	endTransmissionSentStop = sendStop;
	// 0 for 'no twi error'
	return 0;
}
uint8_t MockWire::endTransmission(void)
{
	return endTransmission(true);
}

// Request From method
uint8_t MockWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
	addMethodCall("requestFrom");
	requestedFromAddress = address;
	if (quantity > BUFFER_LENGTH)
	{
		quantity = BUFFER_LENGTH;
	}
	requestedFromQuantity = quantity;
	requestedFromSentStop = sendStop;
	return rxBufferLength;
}
uint8_t MockWire::requestFrom(uint8_t address, uint8_t quantity)
{
	return requestFrom(address, quantity, (uint8_t) true);
}
uint8_t MockWire::requestFrom(int address, int quantity, int sendStop)
{
	return requestFrom((uint8_t) address, (uint8_t) quantity, (uint8_t) sendStop);
}
uint8_t MockWire::requestFrom(int address, int quantity)
{
	return requestFrom(address, quantity, (int) true);
}

// Write method
size_t MockWire::write(const uint8_t *data, size_t quantity)
{
	if (transmitting)
	{
		addMethodCall("write");
		addWrittenData(data, quantity);
	}
	return quantity;
}
size_t MockWire::write(uint8_t data)
{
	return write(&data, 1);
}

// Available method
int MockWire::available(void)
{
	addMethodCall("available");
	return rxBufferLength - rxBufferIndex;
}

// Read method (copy from TwoWire)
int MockWire::read(void)
{
	addMethodCall("read");
	int value = -1;
	if (rxBufferIndex < rxBufferLength)
	{
		value = rxBuffer[rxBufferIndex];
		++rxBufferIndex;
	}
	return value;
}

// Peek method (copy from TwoWire)
int MockWire::peek(void)
{
	addMethodCall("peek");
	int value = -1;
	if (rxBufferIndex < rxBufferLength)
	{
		value = rxBuffer[rxBufferIndex];
	}
	return value;
}

// Flush method (not implemented in TwoWire)
void MockWire::flush(void)
{
	addMethodCall("flush");
}

// Public helper methods


// Private helper methods
void MockWire::addMethodCall(const char *methodName)
{
	int length = strlen(methodName);
	if (methodCallsIndex > 0)
	{
		methodCalls[methodCallsIndex++] = ',';
	}
	for (int i = 0; i < length; i++)
	{
		methodCalls[methodCallsIndex++] = methodName[i];
	}
}
void MockWire::addWrittenData(const uint8_t *data, size_t quantity)
{
	for (size_t i = 0; i < quantity; i++)
	{
		writtenData[writtenQuantity + i] = data[i];
		writtenQuantity++;
	}
}

// Constructor
MockWire::MockWire()
{
	methodCallsIndex = 0;
	rxBufferIndex = 0;
	rxBufferLength = 0;
}