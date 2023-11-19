#include <iostream>

using namespace std;

class Parent{
    public:
    int pub = 5;
    private:
    int pri = 9;
    protected:
    int pro = 20;
};

class Child:private Parent{
    int num = pri;
};

int main()
{
    Child obj;
    return 0;
}