#include <iostream>
#include <cmath>
#include <utility>
#include <string>

template<class T>
double f(T n) {
	return 35.23;
}

template<>
double f<size_t>(size_t n) {
	return sin(5 * n + 123);
}

template<>
double f<int>(int n) {
	return (n<0) ? (log(abs(pow(n, 5) + 223)) / log(2)) : f((size_t)n);
}

template<>
double f<double>(double d) {
	return (d / (d + 223));
}

template<>
double f <std::string>(std::string s) {
	size_t temp = 0;
	for (size_t i = 0, size = s.size(); i < size; ++i) {
		if (isdigit(s[i]))
			++temp;
	}
	return (s.size() != 0) ? (pow((double)temp / (double)s.size(), 2)) : 0;
}

template<>
double f <const char*>(const char* s) {
	size_t temp = 0;
	size_t size = 0;
	while (s[size] != '\0') { ++size; }

	for (size_t i = 0; i < size; ++i) {
		if (isdigit(s[i]))
			++temp;
	}
	return (size != 0) ? (pow((double)temp / (double)size, 2)) : 0;
}

template<>
double f <char*>(char* s) {
	size_t temp = 0;
	size_t size = 0;
	size = strlen(s);

	for (size_t i = 0; i < size; ++i) {
		if (isdigit(s[i]))
			++temp;
	}
	return (size != 0) ? (pow((double)temp / (double)size, 2)) : 0;
}

template <class T, class U>
double f(std::pair<T, U> n) {
	return pow(f(n.second), sin(523 * f(n.first)));
}



int main()
{
//	std::cout << f(-3.0);

	std::cout << f(std::pair<std::string, int> (std::string(),3));

}
