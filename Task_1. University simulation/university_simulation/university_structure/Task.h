/*!
	\file
	\brief Header file containing class Task

	This file contains definition of the class Task, a part of a structure of university simulation
*/


#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

//forward declaration
class Student;

/*!
	\brief Task as a part of studying process
	\details The class contains the information about of the task.
	Some of the information are provided in the constructor, the other one is dependent on the Student
*/
class Task{
private:
	std::string name;
	size_t max_points;
	size_t complexity = 0;
	size_t time = 0;
public:
	Task() = default;
	Task(const std::string& task_name, size_t maximum_points);
	Task(const Task& to_copy);
	bool operator<(const Task& to_compare);
	Task& operator--();
	bool operator==(const Task& to_compare) const;
	size_t time_left();
	size_t get_points();
	void calculateTime(size_t stud_know);
};

#endif //TASK_H
