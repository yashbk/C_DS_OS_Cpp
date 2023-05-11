#include <iostream>
using namespace std;

class book{
	public:
		int novels;
		int fiction;
};

void update_book_details(book *ptr)
{
	cout << "Enter the number of novels:";
	cin >> ptr->novels;

	cout << "Enter the number of fiction:";
	cin >> ptr->fiction;
}

void print(book *ptr)
{
	cout << "Number of novels:"<< ptr->novels << endl;
	cout << "Number of fiction:"<<ptr->fiction << endl;
}

int main()
{
	book obj;
	update_book_details(&obj);
	print(&obj);
}


