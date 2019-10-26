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
//#include "Student.h"

class Student;

/*!
	\brief Class Task
	\details
*/
class Task{
private:
	std::string name;
	size_t max_points;
	size_t complexity = 0;
	std::vector<Knowledge> required_knowledges;
	size_t time = 0;
public:
	Task() = default;
	Task(const std::string& task_name, size_t maximum_points, std::vector<Knowledge> minimal_required_knowledges);
	Task(const Task& to_copy);
	bool operator<(const Task& to_compare);
	Task& operator--();
	Task operator--(int);
	size_t time_left();
	size_t get_points();
	std::vector<Knowledge> get_knowledge_list();
	void calculateTime(Student& to_calc);
};

#endif // !TASK_H
