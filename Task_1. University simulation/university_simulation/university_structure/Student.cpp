#include "Student.h"
#include <vector>
#include <string>
#include <algorithm>
//#include "Task.h"

Student::Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, const std::vector<Subject>& subject_list, const std::vector<Task>& task_list){
	id = students_identification;
	family_name = students_family_name;
	first_name = students_first_name;
	for (size_t i = 0, size = subject_list.size(); i < size; ++i)
		knowledges.push_back(Pair<const Subject*, size_t>(&(subject_list[i]), rand() % 11));
	
	std::sort(knowledges.begin(), knowledges.end(),
		[](Pair<const Subject*, size_t> a, Pair<const Subject*, size_t> b) {
			return (a.second_element < b.second_element);
		});
	
	strategy_type = rand() % 4 + 1;
	tasks = task_list;
}

///*!
//\brief Increase time 
//*/
//Student& Student::operator++() {
//	++time;
//	return *this;
//}

size_t Student::do_easier() {
	return 0;
}

size_t Student::do_heavier() {
	return tasks.size() - 1;
}

size_t Student::do_topPoints() {
	size_t maxpos = 0;
	for (size_t i = 0, size = tasks.size(); i < size; ++i) {
		if (tasks[i].get_points() > tasks[maxpos].get_points())
			maxpos = i;
	}

	return maxpos;
}

size_t Student::do_topKnowledge() {
	//size_t maxpos = knowledges.size() - 1;
	//while (maxpos != 0) {
	//	//if there is no such task in the array
	//	if (std::find(tasks.begin(), tasks.end(), *knowledges[maxpos].first_element) == tasks.end()) {
	//		--maxpos;
	//	}
	//	else {
	//		return std::distance(tasks.begin(), std::find(tasks.begin(), tasks.end(), *knowledges[maxpos].first_element));
	//	}
	//}

	for (int i = knowledges.size() - 1; i >= 0; --i) {
		for (int j = knowledges[i].first_element->size() - 1; j >= 0; --j) {
			if (std::find(tasks.begin(), tasks.end(), (*knowledges[i].first_element)[j]) != tasks.end()) {
				return std::distance(tasks.begin(), std::find(tasks.begin(), tasks.end(), (*knowledges[i].first_element)[j]));
			}
		}
	}
	
	return 0;
}

void Student::updateKnowledge() {
	for (size_t i = 0, know_size = knowledges.size(); i < know_size; ++i) {
		for (size_t j = 0, subj_size = (*knowledges[i].first_element).size(); j < subj_size; ++j) {
			if (current_task == ((*knowledges[i].first_element)[j])) {
				knowledges[i].second_element += (rand() % 3);
				break;
			}
		}
	}
}

void Student::do_task() {
	if (!hasTask) {
		size_t pos;
		if (strategy_type == 1) {
			pos = do_easier();
		}
		else if (strategy_type == 2) {
			pos = do_heavier();
		}
		else if (strategy_type == 3) {
			pos = do_topPoints();
		}
		else {
			pos = do_topKnowledge();
		}
		if (tasks.size()) {
			current_task = tasks[pos];
			size_t stud_task_know = 0;
			for (int i = knowledges.size() - 1; i >= 0; --i) {
				for (size_t j = 0, subj_size = (*knowledges[i].first_element).size(); j < subj_size; ++j) {
					if (current_task == ((*knowledges[i].first_element)[j])) {
						stud_task_know = knowledges[i].second_element;
						i = -1;
						break;
					}
				}
			}

			current_task.calculateTime(*this,stud_task_know);
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
			updateKnowledge();
		}
	}
	++time;
}

std::vector<Pair<const Subject*, size_t>> Student::get_knowledges_list() {
	return knowledges;
}

std::string Student::getFullName() {
	return (family_name + " " + first_name);
}