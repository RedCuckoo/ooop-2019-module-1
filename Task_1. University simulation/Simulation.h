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
	std::vector<Knowledge> fillRandKnowledge(size_t max_value = 10);
	std::vector<Task> getRandTaskSubVector();
	size_t randInt(size_t topVal);
	size_t time = 0;
	std::vector<Student> initial_students;
public:
	Simulation(const std::string& simulation_folder_name);
	void run(size_t given_time);
	std::vector<size_t> generateImproved();
};

#endif // !SIMULATION_H