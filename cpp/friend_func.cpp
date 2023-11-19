#include <iostream>

using namespace std;

class Other;

class Parent{
    public:
    int pub = 5;
    private:
    int pri = 9;
    protected:
    int pro = 20;
    friend void foo(Parent obj);
};

void foo(Parent obj)
{
    cout << obj.pub << endl;
    cout << obj.pri << endl;
    cout << obj.pro << endl;
}

int main()
{
    Parent obj;
    foo(obj);
    return 0;
}