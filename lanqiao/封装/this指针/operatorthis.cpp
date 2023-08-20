#include <iostream>
#include <vector>

class Array {
public:
    Array(int Len = 0) : _Len(Len), data(Len) {
        std::cout << "Array()" << std::endl;
    }

    ~Array() {
        std::cout << "执行析构函数~Array" << std::endl;
    }

    Array& setLen(int Len) {
        _Len = Len;
        data.resize(Len); // Resize the vector to match the new length
        return *this;
    }

    int getLen() const { return _Len; }

    void print() const { std::cout << "Len = " << _Len << std::endl; }

    // 重载 << 运算符为 friend 函数
    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << "[";
        for (size_t i = 0; i < arr._Len; ++i) {
            os << "Element " << i << ": " << arr.data[i];
            if (i < arr._Len - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

private:
    int _Len;
    std::vector<int> data;
};

void stackInstantiation() {
    Array arr1(5);
    std::cout << "this addr: " << arr1.setLen(7) << std::endl;
    std::cout << "obj addr: " << &arr1 << std::endl;

    Array arr2(3);
    std::cout << "this addr: " << arr2.setLen(6) << std::endl;
    std::cout << "obj addr: " << &arr2 << std::endl;
}

int main() {
    stackInstantiation();
    return 0;
}
