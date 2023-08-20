#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	//纯虚函数 ，声明了函数 但是没有实现
	virtual
	void print() const = 0;
	virtual
	void display() const = 0;
	
};

class Derived
: public Base
{
	virtual void print() const override
	{
		cout << "Derived::printf" << endl;
	}

};

class Derived1
: public Derived
{
public:
	virtual void display() const override
	{
		cout << "Derived 1 display " << endl;
	}
};

int main()
{
	Derived1 de;
	de.display();

	Base *pbase = &de;
	pbase-> display();

}