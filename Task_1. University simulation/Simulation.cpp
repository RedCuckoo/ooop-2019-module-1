#include "Simulation.h"
#include <vector>
#include <fstream>

/*!
\brief To fill a container with random integers
\details The function changed passed container and filling it with random values.
\param [out] cont A reference to the container which has to be filled, it has to have a working function push(elem) for adding elements
\param [in] size An amount of elements to be pushed to the container
*/
std::vector<Knowledge> Simulation::fillRandKnowledge(std::vector<Knowledge*> baseVector) {
	std::vector<Knowledge> ans;

	for (size_t i = 0, size = baseVector.size(); i < size; ++i)
		ans.push_back(*baseVector[i]);
	
	for (size_t i = 0, size = baseVector.size(); i < size; ++i)
		ans[i] += randInt(11);
	return ans;
}

/*!
\brief To get a random integer
\details custom implemented randomizer for int
\param [in] topVal The highest possible element for the value
\param [in] negativeValue True if you would like to include negative values in the randomizer, false value otherwise
*/
size_t Simulation::randInt(size_t topVal) {
	return (rand() % topVal);
}

Simulation::Simulation(std::string simulation_folder_name) {
	std::ifstream input(simulation_folder_name + "/Knowledge_list.txt");
	std::string temp_string_1, temp_string_2;
	size_t size = 0;

	while (input.good()) {
		std::getline(input, temp_string_1);
		knowledges.push_back(nullptr);
		knowledges[size++] = new Knowledge(temp_string_1);
	}
	
	input.close();
	size = 0;
	input.open(simulation_folder_name + "/Student_list.txt");

	while (input.good()){
		input >> temp_string_1 >> temp_string_2;
		students.push_back(nullptr);
		students[size++] = new Student(size,temp_string_1,temp_string_2,fillRandKnowledge(knowledges));
	}

}
