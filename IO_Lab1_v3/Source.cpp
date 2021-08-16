#include <iostream>
#include "RandomFunctions.h"
#include "Exit.h"
#include "Simulation.h"

#define AMOUNT_OF_REQUESTS 50*100
#define AVERAGE_GENERATOR_COOLDOWN 500

#define START_REQUEST_PROCESSING 300
#define INCREASING_REQUEST_PROCESSING 100

#define MAX_COOLDOWN 500
#define AMOUNT_OF_TESTING 10

int main() {
	using namespace std;
	Simulation sim;
	cout << "Lab 1. Queuing system. Prepared and developed by:" << endl;
	cout << "Student of BFI1701 group:" << endl;
	cout << "Neretin Ivan" << endl;
	cout << endl;
	cout << "Simulation for system with: " << endl;
	cout << "Amount of requests: " << AMOUNT_OF_REQUESTS << endl;
	cout << "Max cooldown for requests: " << MAX_COOLDOWN << endl;
	cout << "Average time between appearing new requests: " << AVERAGE_GENERATOR_COOLDOWN << endl;
	cout << endl;
	cout << "Target is:" << endl;
	cout << "Find dependency between processing time and lost request probability" << endl;
	cout << endl;
	cout << "Let's try some simulations with different device processing time and look at lost probability:" << endl;
	cout << endl;
	
	for (int i = 1; i <= AMOUNT_OF_TESTING; i++) {
		cout << "SIMULATION " << i << endl;
		int procTime = START_REQUEST_PROCESSING + (i - 1) * INCREASING_REQUEST_PROCESSING;
		cout << "Processing time: " << procTime << endl;
		Exit result = sim.Start(AMOUNT_OF_REQUESTS, AVERAGE_GENERATOR_COOLDOWN, procTime, MAX_COOLDOWN);
		result.OutputStatistics();
		cout << endl;
	}

	return 0;
}