/*!
	\file
	\brief C++ file with implementation of class Subject
*/

#include "Subject.h"
#include <string>
#include <vector>
#include <algorithm>

/*!
	\brief Constructor of the class Subject
	\details The function constructs an object from the provided parameters
	\param [in] subject_name the name of the Subject
	\param [in] subject_task_list the list of the related tasks
*/
Subject::Subject(const std::string& subject_name, std::vector<Task> subject_task_list) {
	name = subject_name;
	std::sort(subject_task_list.begin(), subject_task_list.end(),
		[](Task& a, Task& b) {
			return (a < b);
		});
	task_list = subject_task_list;
}

/*!
	\brief Overloaded operator[]
	\details The overloading allows to get the Task from the subject's list by the index.
	\param [in] index of the task to receive, MUST NOT exceed the amount of the tasks.
	\return The task which is in an array by that index
*/
const Task Subject::operator[](size_t index) const {
	return task_list[index];
}

/*!
	\brief Getter for the amount of the tasks
	\return the amount of the tasks related to the current Subject
*/
size_t Subject::size() const{
	return task_list.size();
}