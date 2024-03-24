#include "iter.hpp"
#include <iostream>

class Awesome
{
	public:
		Awesome(void): _n(42) { return; }
		int get(void) const { return this->_n; }
	private:
		int _n;
};

std::ostream &operator<<(std::ostream & o, Awesome const & rhs) {o << rhs.get(); return o; }

template<typename T>
void print(T & x){std::cout << x << std::endl; return; }

void decValue(int &number) {
    number--;
}

void incValue(int &value) {
    value++;
}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);


	int a[] = {1, 2, 3, 4, 5};
	char b[] = {'a', 'b', 'c'};
	std::string c[] = {"iter.hpp", "main.cpp", "Makefile"};

    ::iter(tab, 5, print);
    ::iter(tab, 5, decValue);
    ::iter(tab, 5, print);
    ::iter(tab, 5, incValue);
    ::iter(tab, 5, print);

    ::iter(a, 5, print);
    ::iter(a, 5, decValue);
    ::iter(a, 5, print);
    ::iter(a, 5, incValue);
    ::iter(a, 5, print);

    ::iter(b, 3, print);

    ::iter(c, 3, print);

    return 0;
}
