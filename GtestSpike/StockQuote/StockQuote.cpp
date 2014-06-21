#include "StdAfx.h"
#include "StockQuote.h"

StockQuote::StockQuote(const char* symbol, int numberOfShares, ITC::SecurityExchangeTransmissionInterface& services)
{
	subtotal = numberOfShares * services.currentPrice(symbol);
}

int StockQuote::total() {
	return subtotal * 1.02 + 10.0;
}


StockQuote::~StockQuote(void)
{
}
