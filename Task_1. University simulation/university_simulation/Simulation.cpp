#include "Simulation.h"
#include <vector>
#include <fstream>
#include <algorithm>

///*!
//\brief To fill a container with random integers
//\details The function changed passed container and filling it with random values.
//\param [out] cont A reference to the container which has to be filled, it has to have a working function push(elem) for adding elements
//\param [in] size An amount of elements to be pushed to the container
//*/
//std::vector<Knowledge> Simulation::fillRandKnowledge(size_t max_value) {
//	std::vector<Knowledge> ans;
//
//	for (size_t i = 0, size = knowledges.size(); i < size; ++i)
//		ans.push_back(knowledges[i]);
//	
//	for (size_t i = 0, size = knowledges.size(); i < size; ++i)
//		ans[i] += (randInt(max_value) + 1);
//	return ans;
//}

/*!
\brief To get a random integer
\details custom implemented randomizer for int
\param [in] topVal The highest possible element for the value
\param [in] negativeValue True if you would like to include negative values in the randomizer, false value otherwise
*/
size_t Simulation::randInt(size_t topVal) {
	return (topVal == 1) ? (rand()%2) : (rand() % topVal);
}

std::vector<Task> Simulation::getRandTaskSubVector() {
	std::vector<Task> ans;
	std::vector<Task> tasks_copy = tasks;

	//array with numbers from 1 to baseVector.size()
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

Simulation::Simulation(const std::string& simulation_folder_name) {
	//TODO: explain numbers
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

void Simulation::run(size_t given_time) {
	for (size_t i = 0; i <= given_time; ++i, ++time) {
		for (size_t j = 0, size = students.size(); j < size; ++j) {
			if (!tasks.size())
				return;
			students[j].do_task();
		}
	}
}

std::vector<std::string> Simulation::generateImproved() {
	std::vector<std::vector<size_t>> deltaAndCounter;
	std::vector<size_t> pair;
	size_t counter = 0;
	size_t size_of_subjects = subjects.size();
	std::vector<Pair<const Subject*, size_t>> current_students_knowledges;
	std::vector<Pair<const Subject*, size_t>> initial_students_knowledges;
	for (size_t i = 0, size_of_students = students.size(); i < size_of_students; ++i) {
		current_students_knowledges = students[i].get_knowledges_list();
		initial_students_knowledges = initial_students[i].get_knowledges_list();
		for (size_t j = 0; j < size_of_subjects; ++j) {
			if (initial_students_knowledges[j].second_element < current_students_knowledges[j].second_element) {
				++counter;
				//pair.push_back(current_students_knowledge[j].get_level() - initial_students_knowledge[j]);
			}
		}
		pair.push_back(i);
		pair.push_back(counter);
		deltaAndCounter.push_back(pair);
		pair.clear();
		counter = 0;
	}

	std::sort(deltaAndCounter.begin(), deltaAndCounter.end(),
		[](std::vector<size_t>& a, std::vector<size_t>& b) {
			return (a[1] < b[1]);
		});

	std::vector<size_t> ans_temp;
	std::vector<std::string> ans;
	for (size_t i = 0, size = deltaAndCounter.size(); i < size; ++i)
		ans_temp.push_back(deltaAndCounter[i][0]);

	for (size_t i = 0, size = ans_temp.size(); i < size; ++i)
		ans.push_back(students[ans_temp[i]].getFullName());


	return ans;
}