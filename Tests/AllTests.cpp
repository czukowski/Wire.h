/*
  AllTests.cpp
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

// Object container
MockWire object;

// Set up a new MockWire object instance
void setUp()
{
	object = MockWire();
}
// Nothing to tear down as of now
void tearDown() {}

TestRef MockWireTest_tests(void);

int main (int argc, const char* argv[])
{
	TestRunner_start();
	TestRunner_runTest(MockWireTest_tests());
	TestRunner_end();
	return 0;
}