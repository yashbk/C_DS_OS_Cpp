#include <iostream>

using namespace std;

class A
{
    public:
    int num;
    virtual void foo()
    {
        cout << "A\n";
    }
};

class B: public A
{
    public:
    int num;
    void foo() const override
    {
        cout << "B\n";
    }
};

int main()
{
    A *ptr = new B;
    ptr->foo();
}