//Swap two numbers through reference arguments
#include <iostream>

using namespace std;

void Swap(int &a,int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	int a=0,b=0;
	cout << "Enter a and b to swap:"<<endl;
	cin >> a >> b;
	cout << "Before swap a:"<<a<<" b:"<<b<<endl;
	Swap(a,b);
	cout << "After swap a:"<<a<<" b:"<<b<<endl;
}

