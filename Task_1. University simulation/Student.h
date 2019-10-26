#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Knowledge.h"

class Student{
private:
	std::string family_name;
	std::string first_name;
	size_t id;
	std::vector<Knowledge> knowledges;
public:
	Student(size_t students_identification, const std::string& students_family_name, const std::string& students_first_name, std::vector<Knowledge> students_set_of_knowledges);


};

#endif // STUDENT_H
