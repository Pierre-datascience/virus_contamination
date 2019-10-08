#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>
#include <math.h>

class Individual
{
private:
	double _x; // x coordinate of the individual position
	double _y; // y coordinate of the individual position
	int _status; // 1 if contaminated and 0 otherwise


public:
	Individual(double, double);   // Initialises the individual position (default status is 0)
	Individual(double, double, int); // Second constructor to generate contaminated individuals
	~Individual();
	void Movement(double);  // 
	double Distance(Individual);
	void Contaminate(std::vector<Individual>&, double, double);

	double GetX(void);
	double GetY(void);
	int GetStatus(void);
};


#endif
