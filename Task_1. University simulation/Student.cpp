#include "Student.h"
#include <vector>
#include <string>
#include <algorithm>
//#include "Task.h"

Student::Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, std::vector<Knowledge> students_set_of_knowledges){
	id = students_identification;
	family_name = students_family_name;
	first_name = students_first_name;
	//std::sort(students_set_of_knowledges.begin(), students_set_of_knowledges.end(),
	//	[](Knowledge& a, Knowledge& b)
	//	{
	//		return (a < b);
	//	});
	knowledges = students_set_of_knowledges;
	strategy_type = rand() % 4 + 1;
}

Student& Student::operator++() {
	++time;
	return *this;
}

Student Student::operator++(int) {
	Student ans = *this;
	++time;
	return ans;
}

std::vector<Knowledge> Student::get_knowledge_list() {
	return knowledges;
}

void Student::updateKnowledge(std::vector<Knowledge> to_update) {
	for (size_t i = 0, size = to_update.size(); i < size; ++i) {
		if (knowledges[i] < to_update[i]) {
			knowledges[i] += (to_update[i].get_level() - knowledges[i].get_level());
		}
	}
}

size_t Student::do_easier(std::vector<Task>& tasks) {
	return 0;
}

size_t Student::do_heavier(std::vector<Task>& tasks) {
	return tasks.size() - 1;
}

size_t Student::do_topPoints(std::vector<Task>& tasks) {
	size_t maxpos = 0;
	for (size_t i = 0, size = tasks.size(); i < size; ++i) {
		if (tasks[i].get_points() > tasks[maxpos].get_points())
			maxpos = i;
	}

	return maxpos;
}

size_t Student::do_topKnowledge(std::vector<Task>& tasks) {
	size_t maxpos = 0;
	size_t maxkno = 0;
	size_t counter = 0;
	std::vector<Knowledge> temp_knowledge_list;
	for (size_t i = 0, size_of_tasks = tasks.size(); i < size_of_tasks; ++i) {
		temp_knowledge_list = tasks[i].get_knowledge_list();
		for (size_t j = 0, size_of_knowledges = knowledges.size(); j < size_of_knowledges; ++j) {
			if (temp_knowledge_list[j] < knowledges[j])
				++counter;
		}
		if (counter > maxkno) {
			maxkno = counter;
			maxpos = i;
		}
		counter = 0;
	}
	return maxpos;
}

void Student::do_task(std::vector<Task>& tasks) {
	if (!hasTask) {
		size_t pos;
		if (strategy_type == 1) {
			pos = do_easier(tasks);
		}
		else if (strategy_type == 2) {
			pos = do_heavier(tasks);
		}
		else if (strategy_type == 3) {
			pos = do_topPoints(tasks);
		}
		else {
			pos = do_topKnowledge(tasks);
		}
		if (tasks.size()) {
			current_task = tasks[pos];
			current_task.calculateTime(*this);
			tasks.erase(tasks.begin() + pos);
			hasTask = true;
		}

	}
	else {
		//already has a task
		--current_task;
		if (!current_task.time_left()) {
			//if time is over
			hasTask = false;
			updateKnowledge(current_task.get_knowledge_list());
		}
	}
	++time;
}