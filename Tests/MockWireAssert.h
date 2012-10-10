/*
  MockWireAssert.h
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
#ifndef MOCKWIREASSERT_H_
#define MOCKWIREASSERT_H_

#include <ArduinoUnit.h>

#define assertWireBegin(expectedAddress, actualObject)\
	assertEquals(expectedAddress, actualObject.initializedAddress);\
	assertEquals("begin", actualObject.methodCalls);

#define assertWireBeginTransmission(expectedAddress, actualObject)\
	assertEquals(expectedAddress, actualObject.transmitAddress);\
	assertEquals(1, actualObject.transmitting);\
	assertEquals("beginTransmission", actualObject.methodCalls);

#define assertWireEndTransmission(expectedSendStop, actualObject)\
	assertEquals(expectedSendStop, actualObject.endTransmissionSentStop);\
	assertEquals(0, actualObject.transmitting);\
	assertEquals("endTransmission", actualObject.methodCalls);

#define assertWireRequestFrom(expectedAddress, expectedQuantity, expectedSendStop, actualObject)\
	assertEquals(expectedAddress, actualObject.requestedFromAddress);\
	assertEquals(expectedQuantity, actualObject.requestedFromQuantity);\
	assertEquals(expectedSendStop, actualObject.requestedFromSentStop);\
	assertEquals("requestFrom", actualObject.methodCalls);

#define assertWireWrite(expectedData, expectedQuantity, actualObject)\
	assertEquals(expectedQuantity, actualObject.writtenQuantity);\
	assertEquals(expectedData, actualObject.writtenData);\
	assertEquals("write", actualObject.methodCalls);

#endif /* MOCKWIREASSERT_H_ */