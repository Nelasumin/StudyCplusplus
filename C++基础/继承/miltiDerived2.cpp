#include "iostream"
#include <ostream>

 

using std::cout;
using std::endl;

class A 
{
public:
    A(long lx = 0)
    :_lx(lx)
    {
        cout << "A(Long = 0) " << endl;
    }

    void setx(long lx)
    {
        _lx = lx;

    }
    void print() const{
        cout << "A::lx = " << _lx << endl;
    }

    ~A()
    {
        cout << "~A() " << endl;
    }

private:
    long _lx;
};

// 虚基指针
// vbotr
// long_lx
class B
: virtual public A
{

};

//虚基指针
//vbptr2
//long _lx
class C
:virtual public A 
{



};
//虚基指针
//vbptr1
//vbptr2
//long _lx
class D 
:public B 
,public C 
{
public:
    D()
    {
        cout << "D() " << endl;
    }
    ~D()
    {
        cout << "~D() " << endl;
    }

};





int main()
{   
    long size;
    cout << "Sizeof(A) = " << sizeof(A) << endl;
    cout << "Sizeof(B) = " << sizeof(B) << endl;
    cout << "Sizeof(C) = " << sizeof(C) << endl;
    cout << "Sizeof(D) = " << sizeof(D) << endl; 
    cout << "Long size = " << sizeof(size) << endl;

    // 多基派生产生的问题：数据成员存储 二义性
    // 解决方法：使用虚拟继承
    D d;
    d.B::setx(10);
    d.B::print();
    
    cout << endl;

    d.C::setx(20);
    d.C::print();

    cout << endl;
    d.setx(30);
    d.print();



    return 0;
    


}