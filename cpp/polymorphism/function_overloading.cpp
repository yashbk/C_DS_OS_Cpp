#include <iostream>

using namespace std;

class Base
{
	public:
		void foo()
		{
			cout << "nothing" << endl;
		}
		void foo(int a)
		{
			cout << a << endl;
		}
		void foo(float m)
		{
			cout << m << endl;
		}
};

int foo()
{
	cout << "hello world\n";
	return 0;
}

void foo(int n)
{
	cout << "hello world\n"<< n<<endl;
}

void foo(int a, int b)
{
	cout << "hello world " << a << "  " << b << endl;
}

void foo(double a, int b)
{
	cout << "hello world " << a << "  " << b << endl;
}


int main()
{
	foo();
	foo(2);
	foo(2,3);
	foo(2.5f,5);

	Base obj;
	obj.foo();
	obj.foo(4);
	obj.foo(3.4f);
	return 0;
}
