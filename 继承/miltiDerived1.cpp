#include "iostream"
#include <ostream>

using std::cout;
using std::endl;

class A{
public:     
    A()
    {
        cout << "A()" << endl;

    }
    void show() const
    {
        cout  << "void A show() const" << endl;
     }

    ~A()
    {
        cout  << "A~() " << endl;
    }
    
};




class b
{
public:    
    b()
    {
        cout << "b()" << endl;

    }
    void show() const
    {
        cout  << "B void show() const" << endl;
     }

    ~b()
    {
        cout  << "b~() " << endl;
    }

};

class c{
public: 
        c()
    {
        cout << "c()" << endl;

    }
    void show2() const
    {
        cout  << "c void show() const" << endl;
     }

    ~c()
    {
        cout  << "c~() " << endl;
    }

};


class D
: public A
, public b
, public c

{
public:
    //基类的构造函数调用顺序 ,与其在派生类的初始化列表没有关系
    //基类构造函数的执行顺序与其基类被派生类继承的先后顺序有关
    D():A(),c(),b()
    {
        cout << "D() " << endl;
    }
    
    ~D()
    {
        cout << "~D()" << endl;
    }
};

int main()
{
    //多继承的时候 , 成员函数访问冲突
    // 解决方案：类名 + 作用域限定符
    D d;
   d.A::show();
   d.b::show();
 
    return 0;
}



