#include "Task.h"
#include <vector>
#include <string>
#include <algorithm>

Task::Task(const std::string& task_name, size_t maximum_points, size_t level_of_complexity, std::vector<Knowledge> minimal_required_knowledges) {
	name = task_name;
	max_points = maximum_points;
	complexity = level_of_complexity;
	std::sort(minimal_required_knowledges.begin(), minimal_required_knowledges.end(),
		[](Knowledge& a, Knowledge& b) {
			return (a < b);
		});
	required_knowledges = minimal_required_knowledges;
}

//TODO:complete overloading
bool Task::operator<(const Task& to_compare) {
	return (complexity < to_compare.complexity);
}