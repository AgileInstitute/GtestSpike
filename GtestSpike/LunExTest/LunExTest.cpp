// LunExTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"

#include "../LunexServices/LunExServices.h"
#include "../StockQuote/StockQuote.h"

TEST(StockQuote, IncludesCommissionAndFee) {
	LunExServices lunexService;
	StockQuote quote("HE3", 100, lunexService);
	EXPECT_EQ(1234, quote.total());
}

TEST(CalculatorTest, Addition) {
	EXPECT_EQ(4, 2 + 2);
}

int main(int argc, char** argv)
{
	std::cout << "Hello World!!!" << std::endl;

	// run all tests
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
