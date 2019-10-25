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
	return *this;
}

/*!
	\brief Incrementing level (field of class Knowledge)
	\details Overloaded right incremention to increment the value of the level
*/
Knowledge Knowledge::operator++(int) {
	Knowledge ans = *this;
	++level;
	return ans;
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