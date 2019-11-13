#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include "Task.h"

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