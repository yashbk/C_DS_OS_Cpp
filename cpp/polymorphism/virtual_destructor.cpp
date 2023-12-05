#include <iostream>

using namespace std;

class Base
{
    public:

    virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived:public Base
{
    public: 

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

class Child: public Derived
{
    public:
    char *num;
    ~Child()
    {
        cout << "Child destructor" << endl;
        delete[] num;
    }

    Child()
    {
        num = new char[20];
    }
};

int main()
{
    Base *ptr = new Child();
    delete ptr;
}