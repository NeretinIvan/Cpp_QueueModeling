#pragma once
#include <list>
#include <iostream>
#include "Request.h"

class Exit {
public:
	std::list<Request*> requestsOut;
	void OutputStatistics();
};