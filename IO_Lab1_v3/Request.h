#pragma once
#define REQUEST_SUCCESS 0
#define REQUEST_LOST 1
#define REQUEST_IN_QUERY 2
#define REQUEST_IN_DEVICE 3

class Request {
public:
	int currentLivingTime;
	int currentWaitingTime;
	int maxWaitingTime;
	int state;
	Request(int maxWaitingTime);
};