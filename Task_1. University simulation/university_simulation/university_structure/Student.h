#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Task.h"
#include "Subject.h"
#include "../../data_structures/Pair.h"

class Student{
private:
	std::string family_name;
	std::string first_name;
	size_t id;
	bool hasTask = 0; 
	size_t time = 0;
	Task current_task;
	std::vector<Task> tasks;
	//sorted by level
	std::vector<Pair<const Subject*, size_t>> knowledges;

	size_t strategy_type;
	size_t do_easier();
	size_t do_heavier();
	size_t do_topPoints();
	size_t do_topKnowledge();
public:
	Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, const std::vector<Subject>& subject_list, const std::vector<Task>& task_list);
	void do_task();
	void updateKnowledge();
	std::vector<Pair<const Subject*, size_t>> get_knowledges_list();
	std::string getFullName();
};

#endif // STUDENT_H
