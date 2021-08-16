#pragma once
#include "Exit.h"

class Simulation {
public:
	Exit Start(int requestCount, int generator1_M, int device_M, int requestTimeOut);
	Simulation();
};