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

// Assert macros
#define TEST_ASSERT_WIRE_BEGIN(expectedAddress, actualObject)\
	TEST_ASSERT_EQUAL_INT(expectedAddress, actualObject.initializedAddress);\
	TEST_ASSERT_EQUAL_STRING("begin", actualObject.methodCalls);
#define TEST_ASSERT_WIRE_BEGIN_TRANSMISSION(expectedAddress, actualObject)\
	TEST_ASSERT_EQUAL_INT(expectedAddress, actualObject.transmitAddress);\
	TEST_ASSERT_EQUAL_INT(1, actualObject.transmitting);\
	TEST_ASSERT_EQUAL_STRING("beginTransmission", actualObject.methodCalls);

// Test object instance
extern MockWire object;

// Set up & tear down functions
extern void setUp();
extern void tearDown();

// External 'get argument' functions
extern MockWire mockWireObjectFactory();
extern int getIntArgument();
extern uint8_t getUint8Argument();

// test functions
void testBeginVoid();
void testBeginUint8();
void testBeginInt();
void testBeginTransmissionUint8();
void testBeginTransmissionInt();

// test suite initialization
TestRef MockWireTest_tests();

#endif /* MOCKWIRETEST_H_ */