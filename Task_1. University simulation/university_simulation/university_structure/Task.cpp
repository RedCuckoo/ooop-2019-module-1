/*!
	\file
	\brief C++ file with implementation of class Task
*/

#include "Task.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

/*!
	\brief Constructor of the class Task
	\details The function constructs an object from the provided parameters.
	The fields name, max_points are initialized from the given parameters.
	The time (<= 30) is time left for the Student to complete it, as in the definition, the Task copy is one of the fields of the Student.
	Complexity is being calculated (<= 10)
	\param [in] task_name the name of the Task
	\param [in] maximum_points the maximum points Student can get for the Task (<= 100)
*/
Task::Task(const std::string& task_name, size_t maximum_points) {
	name = task_name;
	max_points = maximum_points;
	complexity += rand() % 11;
	complexity += (size_t)(max_points * 0.05);
}

/*!
	\brief Copy constructor of the class Task
	\param [in] to_copy the reference to the Task which has to be copied
*/
Task::Task(const Task& to_copy) :
	name(to_copy.name),
	max_points(to_copy.max_points),
	complexity(to_copy.complexity),
	time(to_copy.time)
{	}

/*!
	\brief Overloaded operator<
	\details The overloading allows to sort an array with the lambda function.
	The Task is less to to_compare if it's complexity is less than to_compare's complexity.
	\param [in] to_compare the Task which is comparing with the current one
	\return True value if current Task is smaler than to_compare and false value otherwise
*/
bool Task::operator<(const Task& to_compare) {
	return (complexity < to_compare.complexity);
}

/*!
	\brief Overloaded left decrement
	\details The overloading allows to reduce tasks completion time for the Student by just left decrementing it.
	\return The reference to the current object, to allow instant usage in complicated operations.
*/
Task& Task::operator--() {
	if (time)
		--time;
	return *this;
}

/*!
	\brief Overloaded operator==
	\details The overloading allows to compare the provided task on equality.
	The Task is equal if all the fields besides time are equal.
	\param [in] to_compare the Task which is comparing with the current one
	\return True value if current Task is equal to to_compare and false value otherwise
*/
bool Task::operator==(const Task& to_compare) const {
	return (name == to_compare.name && max_points == to_compare.max_points && complexity == to_compare.complexity);
}

/*!
	\brief Getter for the amount of time stored
	\return the amount of time left for the Student to complete the Task
*/
size_t Task::time_left() {
	return time;
}

/*!
	\brief Getter for the points
	\return The maximum amount of points possible to receive for the task
*/
size_t Task::get_points() {
	return max_points;
}

/*!
	\brief Setter for the time
	\details Calculates time for the specific student, based on his level of knowledge.
	\param [in] stud_know the highest level of the specific knowledge of the subject
*/
void Task::calculateTime(size_t stud_know){
	double temp = complexity * 1.5;
	temp += stud_know * 1.5;
	time = (size_t)temp;
}