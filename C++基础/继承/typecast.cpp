#include "iostream"


using std::cout;
using std::endl;


class Base 
{
public:
    Base()
    :_base()
    {
        cout << "Base() " << endl;
    }

    Base(long base)
    :_base(base)
    {
        cout << "Base(Long)" << endl;
    }
void show() const
{
    cout << "Base::base = " << _base << endl;
}

    ~Base()
    {
         cout << "~Base() " << endl;
    }

private:
    long _base;
};

class Derived 
:public Base
{
public:
    Derived(long base, long derived)
    :Base(base) //调用 基类的构造函数
    ,_derived(derived)
    {
        cout << "Derived(long , long )" << endl;

    }
    void print() const
    {
        show();
        cout << "Derived::_derived = " << _derived << endl;
    }
    
    ~Derived()
    {
        cout << "~Derived" << endl;
    }

private:
    long _derived;
    
};

void test()
{
/**
     Base b1;
    Base b2;
    b1 = b2;
    Derived d1;
    Derived d2;
    //d1 = d2;
    b1 = d1;
    //d2 = b2;
 */
}
void test2()
{   
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl << endl;
     Base base(10);
     base.show();
     cout << endl;

     Derived derived(11111,2222);
     derived.print();

    cout << endl;
    cout << "转换派生类的对象向基类进行转换" <<endl;
    base = derived;         //可以将派生类 对象赋值给基类对象
    base.operator=(derived);
    const Base &rhs = derived;
    base.show();

    cout << " " <<  endl;
    Base &ref = derived; // 将基类的引用绑定到派生类对象中去
    ref.show();

    cout << endl;
    cout << "使用指针打印" << endl;
    Base *pbase = &derived; //基类的指针可以指向派生类的对象
    pbase->show();
#if 0
    cout << endl << "从基类向派生进行转换" << endl;
    derived = base;//1、不能将基类的对象赋值给派生类的对象
    /* derived.operator=(base); */
    /* Derived &operator=(const Derived &rhs) */
    const Derived &rhs = base;

    Derived &ref1 = base;//2、不能将派生类的引用绑定到基类对象上

    Derived *pderived = &base;//3、不能将派生类的指针指向基类对象

#endif
     
}


int main()
{

    test2(); 
    return 0;
}



