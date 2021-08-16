#include "Simulation.h"
#include "Device.h"
#include "Query.h"
#include "Request.h"
#include "RequestGenerator.h"
#include "RandomFunctions.h"
#include "Exit.h"

Exit Simulation::Start(int requestCount, int generator1_M, int device_M, int requestTimeOut) {
	RequestGenerator generator1(generator1_M);
	Query query;
	Device device(device_M);
	Exit exit;

	while (exit.requestsOut.size() < requestCount) {
		generator1.GenerateToQuery(query, requestTimeOut);
		device.ReceiveRequestAndWait(query, exit);
		query.UpdateRequests(exit);
	}

	return exit;
};

Simulation::Simulation() {

};