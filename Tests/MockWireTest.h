/*
  MockWireTest.h
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
#ifndef MOCKWIRETEST_H_
#define MOCKWIRETEST_H_

#include <Arduino.h>
#include <ArduinoUnit.h>
#include "MockWireAssert.h"

// Test 'begin' method without parameters
test(beginVoid) {
	suite.object.begin();
	assertWireBegin(0, suite.object);
}
// Test 'begin' method with int parameter
test(beginInt) {
	suite.object.begin( (int) 88);
	assertWireBegin( (int) 88, suite.object);
}
// Test 'begin' method with uint8_t parameter
test(beginUint8t) {
	suite.object.begin( (uint8_t) 26);
	assertWireBegin( (uint8_t) 26, suite.object);
}
// Test 'beginTransmission' method with uint8_t parameter
test(beginTransmissionUint8t)
{
	suite.object.beginTransmission( (uint8_t) 14);
	assertWireBeginTransmission( (uint8_t) 14, suite.object);
}
// Test 'beginTransmission' method with int parameter
test(beginTransmissionInt)
{
	suite.object.beginTransmission( (int) 36);
	assertWireBeginTransmission( (int) 36, suite.object);
}
// Test 'endTransmission' method without parameters
test(endTransmissionVoid)
{
	suite.object.endTransmission();
	assertWireEndTransmission(true, suite.object);
}
// Test 'endTransmission' method with uint8_t parameter
test(endTransmissionUint8)
{
	suite.object.endTransmission(false);
	assertWireEndTransmission(false, suite.object);
}
// Test 'requestFrom' method with three uint8_t parameters
test(requestFromUintThreeParams)
{
	suite.object.requestFrom( (uint8_t) 32, (uint8_t) 8, (uint8_t) false);
	assertWireRequestFrom(32, 8, false, suite.object);
}
// Test 'requestFrom' method with two uint8_t parameters
test(requestFromUintTwoParams)
{
	suite.object.requestFrom( (uint8_t) 33, (uint8_t) 18);
	assertWireRequestFrom(33, 18, true, suite.object);
}
// Test 'requestFrom' method with three int parameters
test(requestFromIntThreeParams)
{
	suite.object.requestFrom( (int) 12, (int) 12, (int) true);
	assertWireRequestFrom(12, 12, true, suite.object);
}
// Test 'requestFrom' method with two int parameters
test(requestFromIntTwoParams)
{
	suite.object.requestFrom( (int) 64, (int) 9);
	assertWireRequestFrom(64, 9, true, suite.object);
}
// Test 'requestFrom' method with the `quantity` parameter greater than the buffer length
test(requestFromTooLong)
{
	suite.object.requestFrom( (int) 38, (int) BUFFER_LENGTH + 1);
	assertWireRequestFrom(38, BUFFER_LENGTH, true, suite.object);
}
// Test 'write' method with a single int parameter
test(writeOne)
{
	const char* expectedData = "g";
	suite.object.transmitting = 1;
	suite.object.write(0x67);
	assertWireWrite(expectedData, 1, suite.object);
}
// Test 'write' method with const char and int parameters
// Note: TwoWire has several `write` implementations with type conversions inherited from Print, here we test only one of them
test(writeMultiple)
{
	const char* expectedData = "123456";
	int length = strlen(expectedData);
	suite.object.transmitting = 1;
	suite.object.write( (const uint8_t *) "123456", length);
	assertWireWrite(expectedData, length, suite.object);
}

#endif /* MOCKWIRETEST_H_ */