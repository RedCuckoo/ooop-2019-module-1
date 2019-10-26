#include "Simulation.h"
#include <vector>
#include <fstream>

/*!
\brief To fill a container with random integers
\details The function changed passed container and filling it with random values.
\param [out] cont A reference to the container which has to be filled, it has to have a working function push(elem) for adding elements
\param [in] size An amount of elements to be pushed to the container
*/
std::vector<Knowledge> Simulation::fillRandKnowledge(size_t max_value) {
	std::vector<Knowledge> ans;

	for (size_t i = 0, size = knowledges.size(); i < size; ++i)
		ans.push_back(knowledges[i]);
	
	for (size_t i = 0, size = knowledges.size(); i < size; ++i)
		ans[i] += randInt(max_value);
	return ans;
}

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
		tasks_copy.erase(tasks_copy.begin() + temp[pos]);
		temp.erase(temp.begin() + pos);
	}
	return ans;
}

Simulation::Simulation(const std::string& simulation_folder_name) {
	std::ifstream input(simulation_folder_name + "/Knowledge_list.txt");
	std::string temp_string_1, temp_string_2;

	while (input.good()) {
		std::getline(input, temp_string_1);
		knowledges.push_back(Knowledge(temp_string_1));
	}
	
	input.close();

	input.open(simulation_folder_name + "/Student_list.txt");
	size_t size = 0;

	while (input.good()){
		input >> temp_string_1 >> temp_string_2;
		students.push_back(Student(size++,temp_string_1,temp_string_2,fillRandKnowledge()));
	}

	input.close();

	//TODO: explain numbers
	input.open(simulation_folder_name + "/Task_list.txt");
	while (input.good()) {
		std::getline(input, temp_string_1);
		tasks.push_back(Task(temp_string_1, randInt(100), randInt(10), fillRandKnowledge()));
	}

	input.close();

	input.open(simulation_folder_name + "/Subject_list.txt");
	while (input.good()) {
		std::getline(input, temp_string_1);
		subjects.push_back(Subject(temp_string_1, getRandTaskSubVector()));
	}
}
