#include <iostream>

using namespace std;

class Book{
	private:
		static int count;
		int educational;
		int novel;
	public:
		Book()
		{
			cout << "Constructor called\n";
			educational = 0;
			novel = 0;				
			count++;
			cout << "Number of objects are: "<<count<<endl;
		}
		~Book()
		{
			cout << "Destructor called\n";
		}
};

int Book::count;

int main()
{
	Book obj1;
	{
		Book obj2;
	}
	cout << "Hello world\n";
}
