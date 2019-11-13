//Variant 23
//Task 1
//Simulation of university
//Momotenko Yurii
//K-29

#include <random>
#include <string>
#include <time.h>
#include "university_simulation/Simulation.h"

int main()
{
	srand((size_t)time(0));
	Simulation systemSimulation("system_example");
	systemSimulation.run(100);
	std::vector<std::string> improvedStudents = systemSimulation.generateImproved();
	for (size_t i = 0, size = improvedStudents.size(); i < size; ++i)
		std::cout << improvedStudents[i] << '\n';
	return 0;
}