#pragma once

static class RandomFunctions {
public:
	static void init(unsigned int seed);
	static double generateExponential(double M, double koefB);
	static double generateExponential(double M);
};