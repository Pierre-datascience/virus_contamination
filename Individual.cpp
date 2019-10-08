#include "Individual.h"
#include "Annexe.h"
#include <iostream>


Individual::Individual(double xInit, double yInit)
{
	_x = xInit;
	_y = yInit;
	_status = 0;  // By default, a new individual is not contaminated
}

// Second constructor to generate contaminated individuals.
Individual::Individual(double xInit, double yInit, int statusInit) 
{
	_x = xInit;
	_y = yInit;
	_status = statusInit;
}

// Simulate a random walk with step size alpha.
// If the individual 'wants' to move outside of the AccessibleZone, he doesn't move.
void Individual::Movement(double alpha)
{
	double a = _x;
	double b = _y;
	_x += (Random() - 0.5) * alpha;  
	_y += (Random() - 0.5) * alpha;  
	if (!(AccessibleZone(_x, _y)))
	{
		_x = a; 
		_y = b;
	} 
 }

double Individual::Distance(Individual p)
{
	return sqrt(pow((_x - p._x), 0.5) + pow((_y - p._y), 0.5)); // we use the Euclidian distance
}

Individual::~Individual() // Destructor by default
{
}

void Individual::Contaminate(std::vector<Individual>& others, double radius, double proba) 
{
	// Goes across all other individuals
	for (int i = 0; i <= others.size()-1; i++)
	{
		if (Distance(others[i]) <= radius) // If the indivual is close enough
		{
			if (Random() < proba)  // and if the contamination occurs
			{
				others[i]._status = 1; // then the invidual is contaminated
			}
		}
	}
}


// Accessors
double Individual::GetX(void)
{
	return _x;
}

double Individual::GetY(void)
{
	return _y;
}

int Individual::GetStatus(void)
{
	return _status;
}