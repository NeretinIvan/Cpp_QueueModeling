#pragma once
#include "Query.h"
#include "Exit.h"
#include "Request.h"

class Device {
public:
	int M_cooldown;
	int currentCooldown;
	Request* contained;
	void ReceiveRequestAndWait(Query& query, Exit& exit);
	Device(int M_cooldown);
};