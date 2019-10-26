#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include "Student.h"
#include "Task.h"
#include "Knowledge.h"

class Simulation{
private:
	std::vector<Student*> students;
	std::vector<Task> tasks;
	std::vector<Knowledge*> knowledges;
	std::vector<Knowledge> fillRandKnowledge(std::vector<Knowledge*> base_vector);
	size_t randInt(size_t topVal);
public:
	Simulation(std::string);


};

#endif // !SIMULATION_H