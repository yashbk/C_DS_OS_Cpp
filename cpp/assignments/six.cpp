//Find the factorial of a number and return that through reference parameter
#include <iostream>

using namespace std;

void Factorial(int a,int &result)
{
	while(a)
	{
		result = result * a;
		a--;
	}
}

int main()
{
	int a=0,out=1;
	cout << "Enter a to know the factorial of it:"<<endl;
	cin >> a;
	Factorial(a,out);
	cout << "The result is:"<<out<<endl;
}

