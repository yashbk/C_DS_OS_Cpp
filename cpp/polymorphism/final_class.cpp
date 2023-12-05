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

class B final: public A
{
    public:
    int num;
    void foo() override
    {
        cout << "B\n";
    }
};

class C:public B //error: cannot derive from ‘final’ base ‘B’ in derived type ‘C’
{
    public:
    int num;
    void foo() override 
    {
        cout << "C" << endl;
    } 
};


int main()
{
    C c;
}