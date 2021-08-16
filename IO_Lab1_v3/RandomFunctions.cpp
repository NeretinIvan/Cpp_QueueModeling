#include <random>
#include "RandomFunctions.h"
#include <math.h>

void RandomFunctions::init(unsigned int seed) {
	srand(seed);
}

double RandomFunctions::generateExponential(double M) {
	return RandomFunctions::generateExponential(M, 1);
}

double RandomFunctions::generateExponential(double M, double koefB) {
	double rawValue = double(rand()) / RAND_MAX;
	double Z = 1 / M;
	return -log(1 - rawValue) / Z;
}