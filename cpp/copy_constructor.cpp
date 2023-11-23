#include <iostream>

using namespace std;
class Base
{
    public:
    int num;
    int *ptr;
    Base(int a, int b)
    {
        num = a;
        ptr = new int{b};
    }

    void print()
    {
        cout << "current obj: " << this << " address: " << ptr << "  value: " << *ptr << endl;
    }

    Base(const Base& x)
    {
        ptr = new int{*x.ptr};
    }
};


int main()
{
    Base obj(2,3);
    Base obj2 = obj;
    obj.print();
    obj2.print();
    *obj2.ptr = 77;
    obj.print();
    obj2.print();

    return 0;
}