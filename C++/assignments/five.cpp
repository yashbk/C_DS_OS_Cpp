//Add two numbers and return the result through reference parameter
#include <iostream>

using namespace std;

void Add(int a,int b, int &result)
{
	result = a + b;
}

int main()
{
	int a=0,b=0,c=0;
	cout << "Enter a and b"<<endl;
	cin >> a >> b;
	Add(a,b,c);
	cout << "The result is:"<<c<<endl;
}

