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
struct Pair {
	first first_element;
	second second_element;

	Pair(first first_elem, second second_elem);
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

#endif // PAIR_H
