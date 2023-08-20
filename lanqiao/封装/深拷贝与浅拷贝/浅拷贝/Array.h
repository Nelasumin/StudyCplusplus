#ifndef ARRAY_H
#define ARRAY_H

class Array{

public:

    Array();
    // 构造函数
    Array(int count);
    //拷贝构造函数
    Array(const Array & arr);
    ~Array();    
    void setCount(int count);
    int getCount();

private:
    int _count;
};

#endif