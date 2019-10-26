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
	Student(size_t, std::string, std::string, std::vector<Knowledge>);


};

#endif // STUDENT_H
