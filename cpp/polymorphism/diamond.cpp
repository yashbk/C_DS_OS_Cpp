#include <iostream>

using namespace std;

class Base {
public:
    int num = 2;
    virtual void foo() {
        cout << "Base\n";
    }
};

class A : public virtual Base {
public:
    void foo()
    {
        cout << "A\n";
    }
};

class B : public virtual Base {
public:
    void foo()
    {
        cout << "B\n";
    }
};

class C : public A, public B {
public:
    void foo()
    {
        cout << "C\n";
    }
};

int main() {
    Base *ptr = new C;
    cout << ptr->num << endl;
    ptr->Base::foo();
    ptr->foo();
    ptr->foo();
    return 0;
}
