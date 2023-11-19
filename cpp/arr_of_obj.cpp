#include <iostream>
using namespace std;

class book{
private:
	int novel;
	int educational;
	static int count;
public:
	int fiction;
	book(int a,int b,int c = 0)
       	{
		novel = a; 
		educational = b;
		fiction = c;
	       count++;	
	} //Constructor

	void get_data()
	{
		cout << "novel:"<<novel<<endl;
		cout << "educational:"<<educational<<endl;
		cout << "fiction:"<<fiction<<endl;
		cout << "Count is: "<<count<<endl;
	}
	~book()
	{
		cout << "Object deleted\n";
		count--;
	}
};

int book::count;
	

int main()
{
	book obj1(2,3,9);
	book obj2(5,6,8);
	book obj3 = book(6,7);
	book arr[]{obj1,obj2,obj3};
//	book arr[] = {obj1,obj2,obj3};
	for(int i=0;i<sizeof(arr)/sizeof(book);i++)
	{
		arr[i].get_data();
	}
	arr[0].fiction = 89;
	cout << "arr[0].fiction: "<< arr[0].fiction <<endl;
	cout << "obj1.fiction: "<<obj1.fiction<<endl;
	cout << "End of main"<<endl;
	return 0;
}

