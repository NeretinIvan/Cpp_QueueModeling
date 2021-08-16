#include "Request.h"

Request::Request(int maxWaitingTime) {
	Request::currentLivingTime = 0;
	Request::currentWaitingTime = 0;
	Request::maxWaitingTime = maxWaitingTime;
	Request::state = REQUEST_IN_QUERY;
}