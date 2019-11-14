/*!
	\file
	\brief C++ file with implementation of class Student
*/

#include "Student.h"
#include <vector>
#include <string>
#include <algorithm>

/*!
	\brief Constructor for the class Student
	\details The constructor creates and initializes the object from the provided parameters.
	Students receive a specific number of strategy and follow it.
	\param [in] students_identification a unique ID in the current simulation
	\param [in] students_family_name the family name of the current student
	\param [in] students_first_name the first name of the current student
	\param [in] subject_list the list of the subject to store the information about students knowledges in provided subjects
	\param [in] task_list the list of tasks to copy to the object of the Student to prevent doing the same task
*/
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

/*!
	\brief Students strategy
	\details The student chooses the easies task provided.
	It is REQUIRED that this function is called only if the there are available tasks.
	\return Position to the chosen task
*/
size_t Student::do_easier() {
	return 0;
}

/*!
	\brief Students strategy
	\details The student chooses the hardest task provided.
	It is REQUIRED that this function is called only if the there are available tasks.
	\return Position to the chosen task
*/
size_t Student::do_heavier() {
	return tasks.size() - 1;
}

/*!
	\brief Students strategy
	\details The student chooses the task with the most possible points that he can get for the task.
	It is REQUIRED that this function is called only if the there are available tasks.
	\return Position to the chosen task
*/
size_t Student::do_topPoints() {
	size_t maxpos = 0;
	for (size_t i = 0, size = tasks.size(); i < size; ++i) {
		if (tasks[i].get_points() > tasks[maxpos].get_points())
			maxpos = i;
	}

	return maxpos;
}

/*!
	\brief Students strategy
	\details The student chooses the task according to his best level of the knowledge
	It is REQUIRED that this function is called only if the there are available tasks.
	\return Position to the chosen task
*/
size_t Student::do_topKnowledge() {
	std::vector<Pair<const Subject*, size_t>> knowledges_copy = knowledges;
	std::sort(knowledges_copy.begin(), knowledges_copy.end(),
		[](Pair<const Subject*, size_t> a, Pair<const Subject*, size_t> b) {
			return a.second_element < b.second_element;
		});

	for (int i = knowledges_copy.size() - 1; i >= 0; --i) {
		for (int j = knowledges_copy[i].first_element->size() - 1; j >= 0; --j) {
			if (std::find(tasks.begin(), tasks.end(), (*knowledges_copy[i].first_element)[j]) != tasks.end()) {
				return std::distance(tasks.begin(), std::find(tasks.begin(), tasks.end(), (*knowledges_copy[i].first_element)[j]));
			}
		}
	}
	
	return 0;
}

/*!
	\brief Update knowledges after successful task completion
	\details The function updates the knowledge level of the student in the subjects, current_task is related to.
	As a result it can update a few knowledges but not more than by two points (maximum level of knowledge is 10).
*/
void Student::updateKnowledge() {
	for (size_t i = 0, know_size = knowledges.size(); i < know_size; ++i) {
		for (size_t j = 0, subj_size = (*knowledges[i].first_element).size(); j < subj_size; ++j) {
			if (current_task == ((*knowledges[i].first_element)[j])) {
				knowledges[i].second_element += (rand() % 3);
				if (knowledges[i].second_element > 10)
					knowledges[i].second_element = 10;
			}
		}
	}
}

/*!
	\brief Main simulation function
	\details This function keeps on track with global time.
	If the student has a task, it changes time, otherwise it will pick up a new task also.
*/
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

			std::vector<Pair<const Subject*, size_t>> knowledges_copy = knowledges;
			std::sort(knowledges_copy.begin(), knowledges_copy.end(),
				[](Pair<const Subject*, size_t> a, Pair<const Subject*, size_t> b) {
					return a.second_element < b.second_element;
				});

			//searches for the highest level of knowledge with the given task
			for (int i = knowledges_copy.size() - 1; i >= 0; --i) {
				for (size_t j = 0, subj_size = (*knowledges_copy[i].first_element).size(); j < subj_size; ++j) {
					if (current_task == ((*knowledges_copy[i].first_element)[j])) {
						stud_task_know = knowledges_copy[i].second_element;
						i = -1;
						break;
					}
				}
			}

			current_task.calculateTime(stud_task_know);
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

/*!
	\brief Getter for knowledges list
	\details The list is sorted once, while constructing, so its easy to compare student's improvement with the copy of initial list.
	\return current studet's list of knowledges (with levels)
*/
std::vector<Pair<const Subject*, size_t>> Student::get_knowledges_list() {
	return knowledges;
}

/*!
	\brief Getter for the full name of the student
	\return Family name and first name of the student separated by a space.
*/
std::string Student::getFullName() {
	return (family_name + " " + first_name);
}