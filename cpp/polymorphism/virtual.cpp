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
    void foo() override
    {
        cout << "This is from a Derived class\n";
    }
};

class Child:public Derived{
    public:
    void foo() override
    {
        cout << "This is from Child class\n";
    }
};

void print(Base& ptr)
{
    ptr.foo();
}

int main()
{
    Base *ptr = new Child();
    ptr->foo();
    ptr->Base::foo();
    cout << endl << endl;
    Base b;
    Derived d;
    Child c;
    print(b);
    print(d);
    print(c);

}