#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Knowledge.h"
#include "Task.h"

class Student{
private:
	std::string family_name;
	std::string first_name;
	size_t id;
	std::vector<Knowledge> knowledges;
	bool hasTask = 0; 
	size_t time = 0;
	Task current_task;

	size_t strategy_type;
	size_t do_easier(std::vector<Task>& tasks);
	size_t do_heavier(std::vector<Task>& tasks);
	size_t do_topPoints(std::vector<Task>& tasks);
	size_t do_topKnowledge(std::vector<Task>& tasks);
	void updateKnowledge(std::vector<Knowledge> to_update);
public:
	Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, std::vector<Knowledge> students_set_of_knowledges);
	Student& operator++();
	Student operator++(int);
	std::vector<Knowledge> get_knowledge_list();
	void do_task(std::vector<Task>& tasks);
};

#endif // STUDENT_H
