/*!
	\file
	\brief Header file containing class Pair

	This file contains template definition and implementation of such data structure as a Pair, which is customized
*/

#ifndef PAIR_H
#define PAIR_H

#include <iostream>

/*!
	\brief Customized Pair
	\details A custom implementation of Pair<first, second>
	It is possible to create a Pair only through the provided constructor
	The following template classes MUST have operator<< working properly for a nice output.
*/
template<class first, class second>
class Pair {
private:
	first first_element;
	second second_element;

	/*!
	\brief Friended operator<<
	\details Allows to output information with the stream
	*/
	template<class first, class second>
	friend std::ostream& operator<<(std::ostream& out, const Pair<first, second>& to_out);
public:
	/*!
	\brief Constructor
	\details Allowing a default constructor access
	*/
	Pair() = default;
	Pair(first first_elem, second second_elem);

	first getFirst() const;
	second getSecond() const;

	void setFirst(const first& first_elem);
	void setSecond(const first& pr);
	bool operator>(const Pair<first, second>& to_compare) const;
	bool operator>=(const Pair<first, second>& to_compare) const;
	bool operator<(const Pair<first, second>& to_compare) const;
	bool operator<=(const Pair<first, second>& to_compare) const;
	bool operator==(const Pair<first, second>& to_compare) const;
	bool operator!=(const Pair<first, second>& to_compare) const;

	void out();
};

/*!
\brief Constructor
\details A constructor to create a pair with first and second elements relatively
\param[in] first_elem The first element that pair stores
\param[in] second_elem The second element that pair stores
*/
template<class first, class second>
Pair<first, second>::Pair(first first_elem, second second_elem) {
	first_element = first_elem;
	second_element = second_elem;
}

/*!
\brief Getter method for the first_element
\details To get the first_element of the Pair
*/
template<class first, class second>
first Pair<first, second>::getFirst() const {
	return first_element;
}

/*!
\brief Setter method for the first_element
\details To set the first_element of the Pair
*/
template<class first, class second>
void Pair<first, second>::setFirst(const first& first_elem) {
	first_element = first_elem;
}

/*!
\brief Getter method for the second_element
\details To get the second_element of the Pair
*/
template<class first, class second>
second Pair<first, second>::getSecond() const {
	return second_element;
}

/*!
\brief Setter method for the second_element
\details To set the second_element of the Pair
*/
template<class first, class second>
void Pair<first, second>::setSecond(const first& pr) {
	second_element = pr;
}

/*!
\brief Overloaded "is bigger than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is bigger than to_compare and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator>(const Pair<first, second>& to_compare) const {
	return (second_element > to_compare.getSecond()) ? true : false;
}

/*!
\brief Overloaded "is bigger or equal than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is bigger or equal than to_compare and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator>=(const Pair<first, second>& to_compare) const {
	return (second_element >= to_compare.getSecond()) ? true : false;
}

/*!
\brief Overloaded "is less than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is less than to_compare and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator<(const Pair& to_compare) const {
	return (second_element < to_compare.getSecond()) ? true : false;
}

/*!
\brief Overloaded "is less or equal than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is less or equal than to_compare and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator<=(const Pair<first, second>& to_compare) const {
	return (second_element <= to_compare.getSecond()) ? true : false;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator==(const Pair<first, second>& to_compare) const {
	return (second_element == to_compare.getSecond() && first_element == to_compare.getFirst()) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template<class first, class second>
bool Pair<first, second>::operator!=(const Pair<first, second>& to_compare) const {
	return (second_element != to_compare.getSecond() || first_element == to_compare.getFirst()) ? true : false;
}

/*!
\brief Output stored information
\details Print stored fields of the Pair to the console, using <iostream> library
*/
template<class first, class second>
void Pair<first, second>::out() {
	if (this)
		std::cout << first_element << " " << second_element << std::endl;
}

//--------------------end-of-Pair-functions-implementation----------------------------

/*!
\brief Operator<<
\detail Allows to output information with the stream
\param out Stream which is defined automatically, has to be ostream or inherited streams
\param to_out This parameter is passed on the right of "<<", not changeble, the reference to the Pair that has to be outputted
\return Reference to the ostream, to allow continous streaming, like
*/
template <class first, class second>
std::ostream& operator<<(std::ostream& out_stream, const Pair<first, second>& to_out) {
	if (to_out != Pair<first, second>())
		std::cout << to_out.first_element << " " << to_out.second_element;
	return out_stream;
}

#endif // !PAIR_H
