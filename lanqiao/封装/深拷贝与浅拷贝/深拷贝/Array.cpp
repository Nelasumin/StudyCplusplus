#include "Array.h"
#include "iostream"


Array::Array()
{
    std::cout<< "无参构造函数执行" << std::endl;
}

Array::Array(int count)
{   
    this->_count = count;
    Arr = new int[_count];
    std::cout<< "构造函数执行" << std::endl;

}

Array::Array(const Array &arr)
{
    // 浅拷贝
    this->_count = arr._count;
    // 深拷贝正确用法
    this->Arr = new int[_count];
    for (int i = 0; i < _count; i++) {
        this->Arr[i] = arr.Arr[i];
    }
    std::cout << "Array(const Array & arr)" << std::endl;
}

Array::~Array()
{   

    std::cout <<  " ~ 析构 函数" << _count << std::endl;
}

 void Array::printAddress() 
{
    std::cout << "address: " << Arr << std::endl;
}

void Array::setCount(int count)
{
    this->_count = count;
}

int Array::getCount()
{
    return _count;
}

