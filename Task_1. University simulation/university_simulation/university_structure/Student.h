/*!
	\file
	\brief Header file containing class Student

	This file contains definition of the class Student, a part of a structure of university simulation
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Task.h"
#include "Subject.h"
#include "../../data_structures/Pair.h"

/*!
	\brief Student with specific fields for the simulation
	\details An instance of Student as an object.
	The information stored consist of identification fields (such as names and id) and working fields.
	Working fields are created for the simulation system.
	Time synchronizes with general Simulation time and indicators show if the Student has task and which one.
	Also, to prevent Student from doing the same task over and over again, the copy of the initial task list is stored and updated with finishing tasks.
*/
class Student{
private:
	std::string family_name;
	std::string first_name;
	size_t id;

	bool hasTask = 0; 
	size_t time = 0;
	Task current_task;
	std::vector<Task> tasks;

	//sorted by level
	std::vector<Pair<const Subject*, size_t>> knowledges;

	size_t strategy_type;
	size_t do_easier();
	size_t do_heavier();
	size_t do_topPoints();
	size_t do_topKnowledge();
public:
	Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, const std::vector<Subject>& subject_list, const std::vector<Task>& task_list);
	void do_task();
	void updateKnowledge();
	std::vector<Pair<const Subject*, size_t>> get_knowledges_list();
	std::string getFullName();
};

#endif // STUDENT_H
