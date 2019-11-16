//Variant 23
//Task 1
//Simulation of university
//Momotenko Yurii
//K-29

#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include "university_simulation/Simulation.h"

/*!
	\brief Main function
	\details Demonstrates how to run the simulation and receive a list of improved Students.
*/
int main()
{
	srand((size_t)time(0));
	Simulation simulation_example("system_example");
	simulation_example.run();

	return 0;
}