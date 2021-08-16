#include <list>
#include "Request.h"
#include "Exit.h"

#pragma once
class Query {
public:
	std::list<Request*> CurrentQuery;
	Query();
	void UpdateRequests(Exit& exit);
};