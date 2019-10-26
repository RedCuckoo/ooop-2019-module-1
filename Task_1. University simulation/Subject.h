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
};

#endif //SUBJECT_H