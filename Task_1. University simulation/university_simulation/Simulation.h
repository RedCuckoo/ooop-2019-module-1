/*!
	\file
	\brief Header file containing class Simulation

	This file contains definition of a university simulation system
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include "university_structure/Student.h"
#include "university_structure/Task.h"
#include "university_structure/Subject.h"

/*!
	\brief Functions for simulation
	\details A set of functions to be used for simulation.
	The required files are included into the folder system_example
*/
class Simulation{
private:
	std::vector<Student> students;
	std::vector<Subject> subjects;
	std::vector<Task> tasks;
	std::vector<Task> getRandTaskSubVector();
	size_t randInt(size_t topVal);
	size_t time = 0;
	std::vector<Student> initial_students;

	void run_time(size_t given_time);
	void run_tasks(size_t given_amount);
	std::vector<std::string> generateImproved();
public:
	Simulation(const std::string& simulation_folder_name);
	void run();
};

#endif // !SIMULATION_H