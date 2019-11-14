/*!
	\file
	\brief C++ file with implementation of class Simulation
*/

#include "Simulation.h"
#include <vector>
#include <fstream>
#include <algorithm>

/*!
	\brief To get a random integer
	\details A custom implemented randomizer for int
	\param [in] topVal The highest possible element for the value
	\return Random integer number
*/
size_t Simulation::randInt(size_t topVal) {
	return rand() % ++topVal;
}

/*!
	\brief Get a subvector in the vector of tasks
	\details Randomizer for getting a subvector from the stored in class Simulation vector of tasks.
	It is used for filling tasks list for different Subject.
	\return Subvector of tasks
*/
std::vector<Task> Simulation::getRandTaskSubVector() {
	std::vector<Task> ans;
	std::vector<Task> tasks_copy = tasks;

	//array with numbers from 1 to tasks.size()
	std::vector<size_t> temp;
	for (size_t i = 0, size = tasks.size(); i < size; ++i) {
		temp.push_back(i);
	}

	for (size_t i = 0, size = (temp.size()) ? randInt(temp.size()) : 0, pos; i < size; ++i, --size) {
		pos = rand() % size;
		ans.push_back(tasks_copy[temp[pos]]);
		temp.erase(temp.begin() + pos);
	}

	return ans;
}

/*!
	\brief Constructor for class Simulation
	\details The construstor builds the system for the simulation from the provided folder.
	The folder MUST contain three files required for a succesfull project simulation.
	These files are: 
		Student_list.txt (with lines that consist of family name and first name of different students, ID's are assigned automatically)
		Subject_list.txt (with lines that consist of the name of the subject)
		Task_list.txt (with lines that consist of the task description)
	The maximum number of points for the Task varies from 0 to 100.
	\param [in] simulation_folder_name The name of the folder which contains files for system simulation
*/
Simulation::Simulation(const std::string& simulation_folder_name) {
	std::string temp_string_1, temp_string_2;
	std::ifstream input(simulation_folder_name + "/Task_list.txt");

	while (input.good()) {
		std::getline(input, temp_string_1);
		tasks.push_back(Task(temp_string_1, randInt(100)));
	}

	input.close();

	input.open(simulation_folder_name + "/Subject_list.txt");

	while (input.good()) {
		std::getline(input, temp_string_1);
		subjects.push_back(Subject(temp_string_1, getRandTaskSubVector()));
	}

	input.close();

	std::sort(tasks.begin(), tasks.end(),
		[](Task& a, Task& b) {
			return (a < b);
		});

	input.open(simulation_folder_name + "/Student_list.txt");

	size_t size = 0;

	while (input.good()) {
		input >> temp_string_1 >> temp_string_2;
		students.push_back(Student(size++, temp_string_1, temp_string_2, subjects, tasks));
	}

	input.close();

	initial_students = students;
}

/*!
	\brief To run a simulation
	\details Execute the simulation from the constructed object (loading occurs when a constructor is called)
	\param [in] given_time The time in days for which the simulation will run
*/
void Simulation::run(size_t given_time) {
	for (size_t i = 0; i <= given_time; ++i, ++time) {
		for (size_t j = 0, size = students.size(); j < size; ++j) {
			if (!tasks.size())
				return;
			students[j].do_task();
		}
	}
}

/*!
	\brief Generate a list of students who improved
	\details The list is sorted in ascending order by deltas (difference of improvement)
	\return The list of students in order from the greatest delta sum to the lowest
*/
std::vector<std::string> Simulation::generateImproved() {
	//id and delta sum
	std::vector<Pair<size_t, size_t>> deltaSumForStudents;
	std::vector<Pair<const Subject*, size_t>> final_students_knowledges;
	std::vector<Pair<const Subject*, size_t>> initial_students_knowledges;

	for (size_t i = 0, size_of_students = students.size(), size_of_subj = subjects.size(); i < size_of_students; ++i) {
		deltaSumForStudents.push_back(Pair<size_t, size_t>(i, 0));
		final_students_knowledges = students[i].get_knowledges_list();
		initial_students_knowledges = initial_students[i].get_knowledges_list();

		for (size_t j = 0; j < size_of_subj; ++j) {
			deltaSumForStudents[i].second_element += (final_students_knowledges[j].second_element - initial_students_knowledges[j].second_element);
		}
	}

	std::sort(deltaSumForStudents.begin(), deltaSumForStudents.end(),
		[](Pair<size_t, size_t> a, Pair<size_t, size_t> b) {
			return b.second_element < a.second_element;
		});

	std::vector<std::string> improved_students_list;
	for (size_t i = 0, size = deltaSumForStudents.size(); i < size; ++i)
		improved_students_list.push_back(students[deltaSumForStudents[i].first_element].getFullName());

	return improved_students_list;
}