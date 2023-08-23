#include "string.h"
#include "iostream"


using std::cout;
using std::endl;

class String 
{
public:
    String():_pstr(nullptr)
    {
        cout << "String()" << endl;
    }
    String(const char *pstr):
    _pstr(new char[strlen(pstr)+1])
    {
        cout << "String (const char *)" << endl;
        strcpy(_pstr,pstr);
    }


private:
    char *_pstr;
    
};