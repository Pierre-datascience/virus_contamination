#ifndef MISC_H
#define MISC_H
#include "Individual.h"
using namespace std;

// Function that returns True if the individual is going to move within the city boundaries, False otherwise.
bool AccessibleZone(double, double);

// New random function to simulate a uniform distribution on [0, 1].
float Random(void);
													 
// Main function that makes the contamination process go 1 step forward.
// Arguments are the population size, alpha, the radius and the prob of contamination.
// Besides argument passed by reference so that we can modify it.
void Evolution(vector<Individual>&, double, double, double); 

vector<Individual> PopInit(int);

#endif