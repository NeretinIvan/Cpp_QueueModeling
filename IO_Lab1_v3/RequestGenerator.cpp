#include "RequestGenerator.h"
#include "Query.h"
#include "RandomFunctions.h"
#include "Request.h"
#include <math.h>

void RequestGenerator::GenerateToQuery(Query& query, int maxTimeout) {
	if (RequestGenerator::currentCooldown <= 0) {
		Request* newRequest = new Request(maxTimeout);
		query.CurrentQuery.push_back(newRequest);
		RequestGenerator::currentCooldown = ceil(RandomFunctions::generateExponential(RequestGenerator::M_cooldown));
	}
	else {
		RequestGenerator::currentCooldown--;
	}
}

RequestGenerator::RequestGenerator(int cooldown) {
	RequestGenerator::M_cooldown = cooldown;
	RequestGenerator::currentCooldown = ceil(RandomFunctions::generateExponential(RequestGenerator::M_cooldown));
}