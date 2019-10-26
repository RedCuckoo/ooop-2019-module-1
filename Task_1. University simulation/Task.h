/*!
	\file
	\brief Header file
	\details Contains declaration of class Task in it
*/

#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>
#include "Knowledge.h"

/*!
	\brief Class Task
	\details
*/
class Task{
private:
	std::string name;
	size_t max_points;
	size_t complexity;
	std::vector<Knowledge> required_knowledges;
	size_t time = 0;
public:
	Task(const std::string& task_name, size_t maximum_points, size_t level_of_complexity, std::vector<Knowledge> minimal_required_knowledges);
	bool operator<(const Task& to_compare);
};

#endif // !TASK_H
