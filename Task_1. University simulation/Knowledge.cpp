/*!
	\file
	\brief C++ file
	\details Contains implementation of the methods from class Knowledge
*/

#include "Knowledge.h"
#include <string>
#include <iostream>

/*!
	\brief Incrementing level (field of class Knowledge)
	\details Overloaded left incremention to increment the value of the level 
*/
Knowledge& Knowledge::operator++() {
	++level;
	if (level > 10)
		level = 10;
	return *this;
}

/*!
	\brief Incrementing level (field of class Knowledge)
	\details Overloaded right incremention to increment the value of the level
*/
Knowledge Knowledge::operator++(int) {
	Knowledge ans = *this;
	++level;
	if (level > 10)
		level = 10;
	return ans;
}

Knowledge& Knowledge::operator+=(size_t to_add) {
	level += to_add;
	if (level > 10)
		level = 10;
	return *this;
}

/*!
	\brief Less than
	\details Overloaded less than operator, to compare it with other objects from this class
*/
bool Knowledge::operator<(const Knowledge& to_compare) {
	return (level < to_compare.level) ? true : false;
}

/*!
	\brief Getter for the level (field of Knowledge)
*/
size_t Knowledge::get_level() {
	return level;
}

/*!
	\brief Outputting the information
	\details Overloaded streaming operator to output the information about the Knowledge
*/
std::ostream& operator<<(std::ostream& out, const Knowledge& to_out) {
	out << "Knowledge name: " << to_out.name << ", with level " << to_out.level << " of knowledge.";
	return out;
}