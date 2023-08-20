#include <iostream>

using namespace std;

//抽象类的第二种形式：将构造函数设置为protected
class Base
{
public:
private:
protected:
	Base()
	{
		cout << "Base()" << endl;
	}

};

class Derived
:public Base
{	
	public:
	Derived():Base()
	{
		cout << "Derived ~Base"<< endl;
	}

};



int main()
{	//
	//Base base;//调用构造函数 会出错
	Derived derived;


}