#include "iostream"
#include "set"

using namespace std;

class Point 
{
public: 
    // 使用带参数的默认构造方法,并初始化列表x，y
    Point(double x = 0 , double y = 0) :x(x),y(y){
        cout << "Point(double x = " << x << ", double y = " << y << ")" << endl;
    }

    // 拷贝构造函数
    Point(const Point &p)
    {
        cout << "Point(const Point &p:(" << p.x << ", " << p.y << ")" << endl;
        this->x = p.x;
        this->y = p.y;
    }
    // 析构函数，由于没有申请内存，析构函数中不需要做什么
    ~Point()
    {
        cout << "~Point():(" << x << ", " << y << ")" << endl;
    }

    // x,y 绑定的成员函数
    void setPoint(const Point &p) 
    {
        this->x = p.x;
        this->y = p.y;
    }
    void setPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() { return x; }
    double getY() { return y; }


private:
    double x;
    double y;


};




void stackInstantiation1()
{
    Point point[3];
    Point *p = point;
    cout << "p: (" << p->getX() << ", " << p->getY() << ")" << endl;
    p++;
    cout << "p: (" << p->getX() << ", " << p->getY() << ")" << endl;
    p++;
    cout << "p: (" << p->getX() << ", " << p->getY() << ")" << endl;
    point[2].setPoint(3, 4);
    cout << "p: (" << p->getX() << ", " << p->getY() << ")" << endl;
}




int main()
{
    stackInstantiation1();
     return 0;
}