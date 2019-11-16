//Variant 23
//Task 3
//Simulation of university
//Momotenko Yurii
//K-29

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <fstream>


int S = 0;

class Base {
protected:
	static size_t maxId;
	size_t N;
public:
	Base() {
		N = maxId++;
	}

	~Base() {
		S = (2 * S) + N - 23;
	}

	virtual void calc_S(int& s) const = 0;

	std::shared_ptr<Base> b;
};
size_t Base::maxId = 1;


class Alpha : public Base {
public:
	~Alpha() {
		S = S - N;
	}

	void calc_S(int& s) const {
		s = s - N;
		s = (2 * s) + N - 23;
	}
};

class Beta : public Base {
public:
	~Beta() {
		S = S + (3 * N) + 23;
	}

	void calc_S(int& s) const {
		s = s + (3 * N) + 23;
		s = (2 * s) + N - 23;
	}
};

class Red : public Alpha {
public:
	~Red() {
		S = S + (N / 2);
	}

	void calc_S(int& s) const {
		s = s + (N / 2);
		s = s - N;
		s = (2 * s) + N - 23;
	}
};

class Green : public Alpha {
public:
	~Green() {
		S = S - (N / 2) - 11;
	}

	void calc_S(int& s) const {
		s = s - (N / 2) - 11;
		s = s - N;
		s = (2 * s) + N - 23;
	}
};

int predict(const std::list<const Base*>& l_obj) {
	int s = 0;

	auto l_obj_copy = l_obj;
	l_obj_copy.reverse();

	//the last one will be left
	for (auto i : l_obj_copy) {
		i->calc_S(s);
	}

	return s;
}

void combinations(const std::vector<const Base*>& objects, std::vector<size_t>& indexes, std::vector<size_t> previous_indexes = std::vector<size_t>()) {
	for (size_t i = 0, size = indexes.size(); i < size; ++i) {
		previous_indexes.push_back(indexes[i]);

		size_t temp = indexes[i];
		indexes.erase(indexes.begin() + i);
		
		--size;
		combinations(objects, indexes, previous_indexes);
		if (size == 0) {
			std::list<const Base*> new_list_to_predict;
			for (size_t j = 0, f_size = previous_indexes.size(); j < f_size; ++j) 
				new_list_to_predict.push_back(objects[previous_indexes[j]]);

			std::cout << predict(new_list_to_predict);
			std::cout << '\n';
		}

		++size;
		indexes.insert(indexes.begin() + i, temp);
		previous_indexes.erase(--previous_indexes.end());
	}
}

int main() {
	{
		Green g1;
		Green g2;
		Red r1;
		Red r2;
		Alpha a1;
		Beta b1;

		std::vector<const Base*> l_objects;
		l_objects.push_back(&g1);
		l_objects.push_back(&g2);
		l_objects.push_back(&r1);
		l_objects.push_back(&r2);
		l_objects.push_back(&a1);
		l_objects.push_back(&b1);

		std::vector<size_t> indexes;
		for (size_t i = 0, size = l_objects.size(); i < size; ++i)
			indexes.push_back(i);

		std::cout << "Possible combinations are:\n";
		combinations(l_objects, indexes);
	}

	std::cout << "\nReal value: " << S << '\n';
}