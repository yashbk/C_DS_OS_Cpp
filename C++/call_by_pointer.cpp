#include <iostream>

class foo{
	public:
	void change_val(int *ptr);
};

int main()
{
	int num{0};
	foo obj;
	std::cout << "Enter the value\n";
	std::cin>> num;
	std::cout << "Value before: "<< num << std::endl;
	obj.change_val(&num);
	std::cout << "Value After: "<< num << std::endl;
	return 0;
}

void foo::change_val(int *ptr)
{
	std::cout << "Enter value you wish to change to\n";
	std::cin >> *ptr;
}
	
