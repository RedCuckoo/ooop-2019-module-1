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

	//example on how to use the class Simulation
	Simulation systemSimulation("system_example");

	std::cout << "Please, enter the amount of days the program has to simulate: ";
	size_t days;
	std::cin >> days;
	std::cout << '\n';

	systemSimulation.run(days);
	
	std::vector<std::string> improvedStudents = systemSimulation.generateImproved();
	
	for (size_t i = 0, size = improvedStudents.size(); i < size; ++i)
		std::cout << improvedStudents[i] << '\n';

	return 0;
}