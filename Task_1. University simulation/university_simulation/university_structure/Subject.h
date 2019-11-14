/*!
	\file
	\brief Header file containing class Subject

	This file contains definition of the class Subject, a part of a structure of university simulation
*/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include "Task.h"

/*!
	\brief Subject as a part of studying process
	\details The class contains the vector of the related Tasks and the name of the Subject
*/
class Subject{
private:
	std::string name;
	std::vector<Task> task_list;
public:
	Subject(const std::string& subject_name, std::vector<Task> subject_task_list);
	const Task operator[](size_t index) const;
	size_t size() const;
};

#endif //SUBJECT_H