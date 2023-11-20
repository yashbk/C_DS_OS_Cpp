#include <iostream>

using namespace std;

class Base
{
    public:
    virtual void foo()
    {
        cout << "This is from a Base class\n";
    }
};

class Derived:public Base
{
    public:
    void foo()
    {
        cout << "This is from a Derived class\n";
    }
};

class Child:public Derived
{
    public:
    void foo()
    {
        cout << "This is from a Child class\n";
    }
};

void print(Base *ptr)
{
    ptr->foo();
}

int main()
{
    Base *ptr = new Child;
    ptr->foo();
    Base b;
    Derived d;
    Child c;
    print(&b);
    print(&d);
    print(&c);
}