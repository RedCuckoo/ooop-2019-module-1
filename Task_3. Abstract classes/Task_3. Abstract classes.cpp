#include <iostream>

double S;

class Base {
	static size_t maxId;
	size_t N;
public:
	Base() {
		N = maxId++;
	}
	~Base(){
		S = 2 * S + N - 23;
	}


	virtual void func() = 0;
	class Alpha {
		class Red {

		};
		class Green {

		};
	public:

	};
	class Beta {

	};
};


size_t Base::maxId = 1;

int main()
{

}
