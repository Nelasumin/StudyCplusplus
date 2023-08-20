#include "iostream"
#include <future>
/*
* 当参数名称与数据成员名称相同时可使用 this 指针区分。
* 当参数名称与数据成员名称相同时可使用初始化列表，如示例代码 1 中 Point 类。
* 以上两种方式可以区分参数和成员函数，但建议不要起相同的名称。
* 
*
*/
using namespace std;

class Array
{
public:
    Array(int Len = 0):_Len(Len)
    {
        cout << "Array()" << endl;
    }
    ~Array()
    {
        cout << "执行析构函数~Array" << endl;
    }
    Array &setLen(int Len) 
    { 
        this->_Len = Len;
        return *this;
    }
    int getLen() { return _Len; }
    void print() {cout << "Len = " << _Len << endl;}

    

private:
    int _Len;

};


void stackInstantiation()
{
    Array arr1(5);
    arr1.print();
    arr1.setLen(7).print();
}
int main()
{
    stackInstantiation();
    return 0;
}