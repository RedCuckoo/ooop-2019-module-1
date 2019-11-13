#include "Task.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

Task::Task(const std::string& task_name, size_t maximum_points) {
	name = task_name;
	max_points = maximum_points;
	complexity += rand() % 11;
	complexity += (size_t)(max_points * 0.05);
}

Task::Task(const Task& to_copy) :
	name(to_copy.name),
	max_points(to_copy.max_points),
	complexity(to_copy.complexity),
	time(to_copy.time)
{	}

//TODO:complete overloading
bool Task::operator<(const Task& to_compare) {
	return (complexity < to_compare.complexity);
}

Task& Task::operator--() {
	if (time)
		--time;
	return *this;
}

Task Task::operator--(int) {
	Task ans = *this;
	if (time)
		--time;
	return ans;
}

bool Task::operator==(const Task& to_compare) const {
	return (name == to_compare.name && max_points == to_compare.max_points && complexity == to_compare.complexity);
}


size_t Task::time_left() {
	return time;
}

void Task::calculateTime(Student& to_calc, size_t stud_know){
	double temp = complexity * 1.5;
	temp += stud_know * 1.5;
	time = (size_t)temp;
}

size_t Task::get_points() {
	return max_points;
}
//
//inline bool operator==(const Task& to_compare_f, const Task& to_compare_s) {
//	return (to_compare_f.name == to_compare_s.name && to_compare_f.max_points == to_compare_s.max_points && to_compare_f.complexity == to_compare_s.complexity);
//}