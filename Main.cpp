#include "Individual.h"
#include <iostream>
#include "Annexe.h"
using namespace std;
#include <ctime> 


void main()
{
	// Initialise the seed
	srand(time(NULL)); 

	int pop_size;
	double alpha ;
	double radius ;
	double proba ;
	cout << "Choose the population size: " << endl;
	cin >> pop_size;
	cout << "Choose alpha: " << endl;
	cin >> alpha;
	cout << "Choose the radius: " << endl;
	cin >> radius;
	cout << "Choose the probability of contamination: " << endl;
	cin >> proba; 

	vector<Individual> pop = PopInit(pop_size);
	int indicator = 0; // Indicates if there are still contaminated individuals.
	int counter = 0; // Indicates the total number of iterations until full contamination of the population.
	while (indicator == 0)
	{
		Evolution(pop, alpha, radius, proba);
		indicator = 1;
		for (int i = 0; i < pop_size; i++)
		{
			if (pop[i].GetStatus() == 0)
			{
				indicator = 0;
			}
		}
		counter++;
	}
	cout << "All individuals have been contaminated in " << counter << " steps" << endl;
}
