#include "Misc.h"
// Library to use rand() function
#include <cstdlib> 


// Simulate a uniform distribution on [0,1]
float Random(void) 
{
	int r = rand();
	return (((float)r) / (float)RAND_MAX);
}


// Define the city boundaries 
bool AccessibleZone(double x, double y) 
{
	if ((0 < x ) && (x < 40) && (0 < y) && (y < 20)) // Simple zone: 40 * 20 rectangle
	{
		return true;
	}
	else
		return false;
}


// Main function that goes across the population, moves every individual, and potentially contaminates their neighbours.
void Evolution(vector<Individual>& population, double alpha, double radius, double proba)
{
	for (vector<Individual>::iterator it = population.begin(); it != population.end(); ++it)
	{
		(*it).Movement(alpha); //
		if ((*it).GetStatus() == 1)
		{
			(*it).Contaminate(population, radius, proba);
		}
	}
}


// Initialise the population with a given size.
vector<Individual> PopInit(int pop_size) 
{
	vector<Individual> population(pop_size, Individual(0, 0)); 
	for (int i = 1; i < pop_size; i++)
	{
		population[i] = Individual(40 * Random(), 20 * Random()); // Initially each individual is located randomly
	}
	population[0] = Individual(40 * Random(), 20 * Random(), 1); // The first individual is contaminated.
	return population;
}
