//Swap the value of two integers
#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main()
{
	int a,b;
	cout << "Enter a and b"<<endl;
	cin >> a >> b;
	cout <<"Before a:"<<a<<"\tb:"<<b<<endl;
	swap(&a,&b);
	cout <<"After a:"<<a<<"\tb:"<<b<<endl;
	return 0;
}

