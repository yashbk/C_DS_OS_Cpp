#include <iostream>

using namespace std;

class Base
{
    private:
    Base(){
        cout << "Constructor called\n";
    }
    public:
    static Base foo()
    {
        return Base();
    }
};

int main()
{
    Base obj = Base::foo();
    return 0;
}