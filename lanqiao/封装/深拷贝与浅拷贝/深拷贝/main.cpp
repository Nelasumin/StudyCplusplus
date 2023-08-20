#include "iostream"
#include "Array.h"


int main()
{
    Array arr1(5);
    Array arr2 = arr1;
    arr1.printAddress();
    arr2.printAddress();
    return 0;
}