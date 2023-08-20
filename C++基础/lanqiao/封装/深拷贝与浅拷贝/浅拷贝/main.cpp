#include "iostream"
#include "Array.h"


int main()
{
    Array arr1(5);
    Array arr2 = arr1;
    arr2.setCount(10);
    Array arr3(arr2);
    return 0;
}