#pragma once
#include "Query.h"

class RequestGenerator {
public:
	int M_cooldown;
	int currentCooldown;
	void GenerateToQuery(Query& query, int maxTimeout);
	RequestGenerator(int cooldown);
};