#include <iostream>

using namespace std;

class book{
	int novel;
	int educational;
	public:
	void set(int,int);
	friend void dost(book x);
};

void dost(book x)
{
	cout << x.novel << endl << x.educational <<endl;
}

void book::set(int x,int y)
{
	novel = x;
	educational = y;
}

int main()
{
	book obj;
	obj.set(2,3);
	dost(obj);
}
