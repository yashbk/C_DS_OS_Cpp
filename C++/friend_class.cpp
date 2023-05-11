#include <iostream>
using namespace std;

class two; //forward declaration

class one{
	int num;
	public:
	void set_num(int);
	friend class two;
};

class two
{
	public:
	void func(one obj);
};


void two::func(one obj)
{
	cout << obj.num << endl;

}

void one::set_num(int n)
{
	num = n;
}

int main()
{
	one obj;
	obj.set_num(34);
	two obj2;
	obj2.func(obj);
}
	

