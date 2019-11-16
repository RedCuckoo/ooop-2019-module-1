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
void Simulation::run_time(size_t given_time) {
	size_t tasks_counter = 0;
	for (size_t i = 0; i <= given_time; ++i, ++time) {
		for (size_t j = 0, size = students.size(); j < size; ++j) {
			if (!tasks.size())
				return;
			if (students[j].do_task())
				++tasks_counter;
		}
	}
	std::cout << "During " << given_time << " days students completed " << tasks_counter << " tasks.\n\n";
}

/*!
	\brief To run a simulation
	\details Execute the simulation from the constructed object (loading occurs when a constructor is called)
	\param [in] given_tasks The amount of tasks students have to finish in order to complete the simulation
*/
void Simulation::run_tasks(size_t given_amount) {
	size_t i = 0;
	size_t stds_size = students.size();
	size_t tsks_size = given_amount;
	if (!stds_size)
		return;

	if (tsks_size > (stds_size * tasks.size())) {
		std::cout << "Unable to run, students don't have enough tasks to do\n\n";
		return;
	}
	
	size_t time_counter = 0;

	while (tsks_size) {
		if (students[i].do_task())
			--tsks_size;

		++time_counter;

		
		if (i + 1 == stds_size)
			i = 0;
		else
			++i;
	}

	std::cout << "During " << time_counter << " days students completed " <<given_amount << " tasks.\n\n";
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

void Simulation::run() {
	size_t choice = 0;
	while (choice != 1 && choice != 2) {
		std::cout << "Please choose the endpoint of the simulation:\n";
		std::cout << "1 - amount of days the simulation will run\n";
		std::cout << "2 - amount of tasks students have to complete\n=> ";
		std::cin >> choice;
	}
	
	if (choice == 1) {
		std::cout << "Please, enter the amount of days the program has to simulate: ";
		size_t days;
		std::cin >> days;
		std::cout << '\n';

		run_time(days);
	}
	else {
		std::cout << "Please, enter the amount of tasks the students have to complete: ";
		size_t tasks;
		std::cin >> tasks;
		std::cout << '\n';

		run_tasks(tasks);
	}

	std::cout << "The list of approved students sorted in ascending order by deltas (differences of improvement):\n";
	std::vector<std::string> improvedStudents = generateImproved();

	for (size_t i = 0, size = improvedStudents.size(); i < size; ++i)
		std::cout << improvedStudents[i] << '\n';
}