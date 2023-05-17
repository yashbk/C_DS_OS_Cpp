#include <iostream>

using namespace std;

class Book{
	public:
		int novel;
	private:
		int educational; 
	protected:
		int fiction; 
	public:
		Book(){novel=educational=fiction=0;cout << "Parent constructor called\n";}
		~Book(){cout << "Parent destructor called\n";}
		void set_novel(int n = 0){novel = n;}
		void set_educational(int n = 0){educational = n;}
		void set_fiction(int n = 0){fiction = n;}
		int get_private(){return educational;}
};

class Student:public Book{
	private:
		string name;
		int roll_no;
		int age;
	public:
		Student(){cout << "Child constructor called\n";}
		~Student(){cout << "Child destructor called\n";}
		void set_student_info(string name,int roll,int age)
		{
			this->name = name;
			roll_no = roll;
			this->age = age;
		}
		void print()
		{
			cout << "NAME:\t"<<name<<endl;
			cout << "ROLL:\t"<<roll_no<<endl;
			cout << "AGE:\t"<<age<<endl;
			cout << "novel:\t"<<novel<<endl;
			//cout << "educational:\t"<<educational<<endl;  //This is private so cannot be accessed by child class.
			cout << "educational:\t" << get_private()<<endl;
			cout << "fiction:\t"<<fiction<<endl; //This is protected so it can be accessed from child class
		}
};


int main()
{
	Student yash;
	
	yash.set_student_info("yashas",28,24);
	yash.set_novel(4);
	yash.set_educational(9);
	yash.set_fiction(12);
	yash.print();
	return 0;
}
