// LunExTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"

int main(int argc, char** argv)
{
	std::cout << "Hello World!!!" << std::endl;

	// run all tests
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}