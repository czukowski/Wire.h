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
#include <embUnit/embUnit.h>
#include <MockWire.h>

MockWire objectFactory()
{
	return MockWire();
}

void setUp(void)
{}

void tearDown(void)
{}

void testBeginVoid()
{
	MockWire object = objectFactory();
	object.begin();
	TEST_ASSERT_EQUAL_INT(0, object.initializedAddress);
	TEST_ASSERT_EQUAL_STRING("begin", object.methodCalls);
}
void testBeginUint8()
{
	uint8_t arg = 12;
	MockWire object = objectFactory();
	object.begin(arg);
	TEST_ASSERT_EQUAL_INT(12, object.initializedAddress);
	TEST_ASSERT_EQUAL_STRING("begin", object.methodCalls);
}
void testBeginInt()
{
	int arg = 88;
	MockWire object = objectFactory();
	object.begin(arg);
	TEST_ASSERT_EQUAL_INT(88, object.initializedAddress);
	TEST_ASSERT_EQUAL_STRING("begin", object.methodCalls);
}

TestRef MockWireTest_tests(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture( (char*) "testBeginVoid", testBeginVoid),
		new_TestFixture( (char*) "testBeginUint8", testBeginUint8),
		new_TestFixture( (char*) "testBeginInt", testBeginInt),
	};
	EMB_UNIT_TESTCALLER(MockWireTest, (char*) "MockWireTest", setUp, tearDown, fixtures);

	return (TestRef)&MockWireTest;
}
