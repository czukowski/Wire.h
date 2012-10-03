/*
  MockWireTest.cpp
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
#include <embUnit/embUnit.h>
#include <MockWire.h>
#include "MockWireTest.h"

TestRef MockWireTest_tests()
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture( (char*) "testBeginVoid", testBeginVoid),
		new_TestFixture( (char*) "testBeginUint8", testBeginUint8),
		new_TestFixture( (char*) "testBeginInt", testBeginInt),
		new_TestFixture( (char*) "testBeginTransmissionUint8", testBeginTransmissionUint8),
		new_TestFixture( (char*) "testBeginTransmissionInt", testBeginTransmissionInt),
	};
	EMB_UNIT_TESTCALLER(MockWireTest, (char*) "MockWireTest", setUp, tearDown, fixtures);

	return (TestRef) &MockWireTest;
}

void testBeginVoid()
{
	object.begin();
	TEST_ASSERT_WIRE_BEGIN(0, object);
}
void testBeginUint8()
{
	object.begin( (uint8_t) 26);
	TEST_ASSERT_WIRE_BEGIN( (uint8_t) 26, object);
}
void testBeginInt()
{
	object.begin( (int) 88);
	TEST_ASSERT_WIRE_BEGIN( (int) 88, object);
}
void testBeginTransmissionUint8()
{
	object.beginTransmission( (uint8_t) 14);
	TEST_ASSERT_WIRE_BEGIN_TRANSMISSION( (uint8_t) 14, object);
}
void testBeginTransmissionInt()
{
	object.beginTransmission( (int) 36);
	TEST_ASSERT_WIRE_BEGIN_TRANSMISSION( (int) 36, object);
}