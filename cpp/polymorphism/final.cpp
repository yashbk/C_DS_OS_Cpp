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
    void foo() final
    {
        cout << "B\n";
    }
};

class C:public B
{
    public:
    int num;
    void foo() //error: virtual function ‘virtual void C::foo()’ overriding final function
    {
        cout << "C" << endl;
    } 
};


int main()
{
    C c;
}