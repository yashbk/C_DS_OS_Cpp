#include <iostream>

class some{
	private:
		int num;
	public:
		void set_num(int);
		void get_num();
};

void some::set_num(int num)
{
	this->num = num;
}

void some::get_num()
{
	std::cout << "Num is "<<num<<std::endl;
}

int main()
{
	some obj;
	int num;
	std::cout << "Enter the number\n";
	std::cin >> num;
	obj.set_num(num);
	obj.get_num();
}


