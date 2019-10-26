#include "Student.h"
#include <vector>
#include <string>
#include <algorithm>

Student::Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, std::vector<Knowledge> students_set_of_knowledges){
	id = students_identification;
	family_name = students_family_name;
	first_name = students_first_name;
	std::sort(students_set_of_knowledges.begin(), students_set_of_knowledges.end(),
		[](Knowledge& a, Knowledge& b)
		{
			return (a < b);
		});
	knowledges = students_set_of_knowledges;
}
