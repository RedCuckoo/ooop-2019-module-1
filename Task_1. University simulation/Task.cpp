#include "Task.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

Task::Task(const std::string& task_name, size_t maximum_points, std::vector<Knowledge> minimal_required_knowledges) {
	name = task_name;
	max_points = maximum_points;
	//std::sort(minimal_required_knowledges.begin(), minimal_required_knowledges.end(),
	//	[](Knowledge& a, Knowledge& b) {
	//		return (a < b);
	//	});
	required_knowledges = minimal_required_knowledges;
	for (size_t i = 0, size = required_knowledges.size(); i < size; ++i) {
		complexity += minimal_required_knowledges[i].get_level();
	}
	if (minimal_required_knowledges.size())
		complexity = (size_t)((complexity / minimal_required_knowledges.size())*0.5 + maximum_points * 0.05);
	else
		complexity = (size_t)(maximum_points * 0.05);
}

Task::Task(const Task& to_copy) :
	name(to_copy.name),
	max_points(to_copy.max_points),
	complexity(to_copy.complexity),
	required_knowledges(to_copy.required_knowledges),
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

size_t Task::time_left() {
	return time;
}

void Task::calculateTime(Student& to_calc){
	double temp = 0;
	std::vector<Knowledge> students_knowledges = to_calc.get_knowledge_list();
	for (size_t i = 0, size = required_knowledges.size(); i < size; ++i) {
		temp = temp + (required_knowledges[i].get_level() / students_knowledges[i].get_level());
	}

	temp /= required_knowledges.size();
	temp *= 1.5;
	temp += complexity * 1.5;
	time = (size_t)temp;
}

std::vector<Knowledge> Task::get_knowledge_list() {
	return required_knowledges;
}

size_t Task::get_points() {
	return max_points;
}