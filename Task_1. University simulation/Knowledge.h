/*!
	\file
	\brief Header file
	\details Contains declaration of class Knowledge in it
*/
#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <string>

/*!
	\brief Class Knowledge
	\details Reflects the level of various knowledges the student can have
*/
class Knowledge
{
private:
	///name of the knowledge
	std::string name;
	///level of the knowledge, maximum is 10, minimum is 0
	size_t level;

	friend  std::ostream& operator<<(std::ostream&, const Knowledge&);
public:
	Knowledge(const std::string& name_of_knowledge, size_t level_of_knowledge = 0) : name(name_of_knowledge), level(level_of_knowledge){	}
	Knowledge& operator++();
	Knowledge operator++(int);
	Knowledge& operator+= (size_t);
	bool operator<(const Knowledge&);
	size_t get_level();
};

#endif //KNOWLEDGE_H