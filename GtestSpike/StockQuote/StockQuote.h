#pragma once

#include "../LunexServices/ITC/SecurityExchangeTransmissionInterface.h"
class StockQuote
{
public:
	StockQuote(const char* symbol, int numberOfShares, ITC::SecurityExchangeTransmissionInterface& services);
	~StockQuote(void);
	int total();
};

