//Add two numbers and return the result through the third pointer argument
#include <iostream>

using namespace std;

void addVal(int *a,int *b,int *result)
{
	*result =  *a + *b;
}

int main()
{
	int a,b,result;
	cout << "Enter a and b"<<endl;
	cin >> a >> b;
	addVal(&a,&b,&result);
	cout << "Result is:"<<result<<endl;
	return 0;
}

