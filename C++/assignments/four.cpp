//Generate the factorial of a number and return that through the second pointer argument
#include <iostream>

using namespace std;

void factorial(int *a,int *result)
{
	int val = *a;
	while(val)
	{
		*result *=val;
		val--;
	}
}

int main()
{
	int a = 0,result = 1;
	cout << "Enter a:"<<endl;
	cin >> a;
	factorial(&a,&result);
	cout <<"Factorial of "<<a<<" is:"<<result<<endl;
	return 0;
}

