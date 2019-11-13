#include "Subject.h"
#include <string>
#include <vector>
#include <algorithm>

Subject::Subject(const std::string& subject_name, std::vector<Task> subject_task_list) {
	name = subject_name;
	std::sort(subject_task_list.begin(), subject_task_list.end(),
		[](Task& a, Task& b) {
			return (a < b);
		});
	task_list = subject_task_list;
}

const Task Subject::operator[](size_t index) const {
	return task_list[index];
}

size_t Subject::size() const{
	return task_list.size();
}