#include <iostream>
#include <list>

int S = 0;

class Base {
protected:
	static size_t maxId;
	size_t N;
public:
	Base() {
		N = maxId++;
	}
	
	~Base(){
		S = (2 * S) + N - 23;
	}

	virtual void calc_S(int& s) = 0;

	std::shared_ptr<Base> b;
};
size_t Base::maxId = 1;


class Alpha : public Base {
public:
	~Alpha() {
		S = S - N;
	}

	void calc_S(int& s) {
		s =  s - N;
	}
};

class Beta : public Base {
public:
	~Beta() {
		S = S + (3 * N) + 23;
	}

	void calc_S(int& s) {
		s =  s + (3 * N) + 23;
	}
};

class Red : public Alpha {
public:
	~Red() {
		S = S + (N / 2);
	}

	void calc_S(int& s) {
		s =  s + (N / 2);
	}
};

class Green : public Alpha {
public:
	~Green() {
		S = S - (N / 2) - 11;
	}

	void calc_S(int& s) {
		s = s - (N / 2) - 11;
	}
};

int predict(const std::list<std::shared_ptr<Base>>& l_obj) {
	int s = 0;
	//for (auto i = l_obj.begin(), e = l_obj.end(); i != e; ++i) {
	for (const auto& i : l_obj){
		i->calc_S(s);
	}
	return s;
}

int main(){
	{	
		std::shared_ptr<Green> g1(new Green);
		//std::shared_ptr<Green> g2(new Green);
		///std::shared_ptr<Red> r1(new Red);
		//std::shared_ptr<Red> r2(new Red);
		//std::shared_ptr<Alpha> a1 (new Alpha);
		//std::shared_ptr<Beta> b1 (new Beta); 

		std::list<std::shared_ptr<Base>> l_objects;
		//l_objects.push_back(b1);
		//l_objects.push_back(a1);
		//l_objects.push_back(r2);
		////l_objects.push_back(r1);
		//l_objects.push_back(g2);
		l_objects.push_back(g1);

		std::cout << "Predicted value: " <<predict(l_objects);
	}

	

	std::cout << "\nReal value: " << S;


}
