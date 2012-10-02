/*
 * embUnit_Tests.cpp
 *
 * Created: 28.9.2012 9:28:15
 *  Author: czukowski
 */ 
#include <embUnit/embUnit.h>

TestRef MockWireTest_tests(void);

int main (int argc, const char* argv[])
{
	TestRunner_start();
	TestRunner_runTest(MockWireTest_tests());
	TestRunner_end();
	return 0;
}