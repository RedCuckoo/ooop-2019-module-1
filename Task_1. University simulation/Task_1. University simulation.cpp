//Variant 23
//Task 1
//Simulation of university
//Momotenko Yurii
//K-29

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Knowledge.h"
#include "Student.h"
#include "Simulation.h"
#include <time.h>

int main()
{
	srand((size_t)time(0));
	Simulation systemSimulation("system_example");
	systemSimulation.run(100);
	std::vector<size_t> improvedStudents = systemSimulation.generateImproved();
}