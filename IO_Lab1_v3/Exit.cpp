#include "Exit.h"
#include <list>
#include <iostream>

void Exit::OutputStatistics() {
	int lost = 0;
	int success = 0;
	int requestCount = 0;
	int waitingSuccess = 0;
	int waitingOverall = 0;

	for (std::list<Request*>::iterator iter = requestsOut.begin(); iter != requestsOut.end(); iter++) {
		if (iter._Ptr->_Myval->state == REQUEST_LOST) {
			lost++;
		}
		if (iter._Ptr->_Myval->state == REQUEST_SUCCESS) {
			success++;
			waitingSuccess += iter._Ptr->_Myval->currentWaitingTime;
		}
		requestCount++;
		waitingOverall += iter._Ptr->_Myval->currentWaitingTime;
		delete[] iter._Ptr->_Myval;
	}

	std::cout << "Requests overall: " << requestCount << std::endl;
	std::cout << "Requests lost: " << lost << std::endl;
	std::cout << "Requests received succesfully: " << success << std::endl;
	std::cout << "Average waiting for received requests: " << double(waitingSuccess) / success << std::endl;
	std::cout << "Average waiting for all requests: " << double(waitingOverall) / requestCount << std::endl;
	std::cout << "Probability to lost request: " << 100 * double(lost) / requestCount << "%" << std::endl;
}
