// LunExTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
using ::testing::Return;
using ::testing::Throw;

#include "../LunexServices/LunExServiceUnavailableException.h"
#include "../LunexServices/LunExServices.h"
#include "../StockQuote/StockQuote.h"

class MockService : public ITC::SecurityExchangeTransmissionInterface {
public:
	MOCK_METHOD1(currentPrice, double(const char* symbol));
};

class StockQuoteFixture : public ::testing::Test {
protected:
	virtual void SetUp() {
	}
	MockService lunexService;
};

TEST_F(StockQuoteFixture, IncludesCommissionAndFee) {
	EXPECT_CALL(lunexService, currentPrice("HE3")).WillOnce(Return(12));

	StockQuote quote("HE3", 100, lunexService);

	EXPECT_EQ(1234, quote.total());
}

TEST_F(StockQuoteFixture, ThrowsEarthboundException) {
	EXPECT_CALL(lunexService, currentPrice("HE3")).WillOnce(Throw(LunExServiceUnavailableException()));

	EXPECT_THROW(StockQuote("HE3", 100, lunexService), LunExServiceUnavailableException);

}

TEST(CalculatorTest, Addition) {
	EXPECT_EQ(4, 2 + 2);
}

int main(int argc, char** argv)
{
	// run all tests
	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}
