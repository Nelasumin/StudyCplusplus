#include "Array.h"
#include "iostream"


Array::Array()
{
    std::cout<< "无参构造函数执行" << std::endl;
}

Array::Array(int count)
{   
    std::cout<< "构造函数执行" << std::endl;
    this->_count = count;
}

Array::Array(const Array &arr)
{
    this->_count = arr._count;
    std::cout << "Array(const Array & arr)" << std::endl;
}

Array::~Array()
{
    std::cout <<  " ~ 析构 函数" << _count << std::endl;
}

void Array::setCount(int count)
{
    this->_count = count;
}

int Array::getCount()
{
    return _count;
}

