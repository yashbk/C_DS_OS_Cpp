#include <iostream>
#include <string>

using namespace std;

class student{
	private:
		string name;
		int rollno;
		int age;
	public:
		student(char*,int,int);
		void get_data();
};

student::student(char *name,int roll,int age)
{
	this->name = name;
	rollno = roll;
	this->age = age;
}

void student::get_data()
{
	cout << "NAME: "<<name<<endl;
	cout << "ROLL NO: "<<rollno<<endl;
	cout << "AGE: "<<age<<endl;
}

int main()
{
	student *ptr = new student("yashas",22,24);
	ptr->get_data();
	return 0;
}
