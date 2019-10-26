#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include "Student.h"
#include "Task.h"
#include "Subject.h"
#include "Knowledge.h"

class Simulation{
private:
	std::vector<Student> students;
	std::vector<Subject> subjects;
	std::vector<Task> tasks;
	std::vector<Knowledge> knowledges;
	std::vector<Knowledge> fillRandKnowledge(size_t max_value = 11);
	std::vector<Task> getRandTaskSubVector();
	size_t randInt(size_t topVal);
public:
	Simulation(const std::string& simulation_folder_name);


};

#endif // !SIMULATION_H