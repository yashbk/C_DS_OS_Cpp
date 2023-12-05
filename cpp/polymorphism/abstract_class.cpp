#include <iostream>

using namespace std;

class Base
{
    protected:
    int a = 5;
    int b = 3;
    
    public:
    Base(int x, int y): a(x),b(y){}
    virtual void add() = 0;
    virtual void sub() = 0;
};

class Derived : public Base
{
    public:
    Derived(int x,int y):Base(x,y){}
    void add() { cout <<  a+b << endl;}
    void sub() { cout <<  a-b << endl;}
};

int main()
{
    Derived obj(2,3);
    obj.add();
    obj.sub();
    return 0;
}