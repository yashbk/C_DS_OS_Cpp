//Classes and objects, access specifier and friend class

#include <iostream>

class Something{
    private:
    int num;
    public:
    void set_num(int num);
    int get_num(void);
};

void Something::set_num(int num)
{
    this->num = num;
}

int Something::get_num(void)
{
    return num;
}

int main()
{
    Something obj;
    obj.set_num(4);
    std::cout << obj.get_num() << std::endl;
    return 0;
}