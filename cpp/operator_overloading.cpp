#include <iostream>

using namespace std;

class Base
{
    public:
    int num = 0;

    Base(int n):num(n){}

    Base operator+(Base& obj) 
    {
        Base x;
        x.num = num + obj.num;
        return x;
    }
};

int main()
{
    Base obj1(3);
    Base obj2(6);
    Base obj3 = obj1 + obj2;
    cout << obj3.num<<endl;
}