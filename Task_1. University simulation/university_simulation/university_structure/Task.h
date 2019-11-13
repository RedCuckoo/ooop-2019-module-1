/*!
	\file
	\brief Header file
	\details Contains declaration of class Task in it
*/

#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

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
	size_t time = 0;
public:
	Task() = default;
	Task(const std::string& task_name, size_t maximum_points);
	Task(const Task& to_copy);
	bool operator<(const Task& to_compare);
	Task& operator--();
	Task operator--(int);
	bool operator==(const Task& to_compare) const;
	size_t time_left();
	size_t get_points();
	void calculateTime(Student& to_calc, size_t stud_know);
	//friend bool operator==(const Task& to_compare_f, const Task& to_compare_s);
};

#endif //TASK_H
