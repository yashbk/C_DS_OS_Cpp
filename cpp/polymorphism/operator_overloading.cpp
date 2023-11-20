/*
Polymorphism
compile time
    -> function overloading
    -> operator overloading
runtime 
    -> virtual function
    -> pure virtual function

*/

#include <iostream>

using namespace std;

class Num
{
    private:
    unsigned int num1 = 1;
    double num2 = 1.5;

    public:

    Num(int a,double b):num1(a),num2(b){}
    Num(){}
    
    Num operator+(Num& obj)  // Num& obj = obj2
    {
        Num temp;
        temp.num1 = num1 + obj.num1;
        temp.num2 = num2 + obj.num2;
        return temp;
       // return Num(this->num1 + obj.num1,this->num2 + obj.num2);
    }

    void display()
    {
        Num obj;
        cout << "obj1 is  " << obj.num1 << "  " << obj.num2 << endl;
        cout << "obj2 is  " << obj.num1 << "  " << obj.num2 << endl;
        cout << "current obj: " << num1 << "  "  << num2 << endl << endl;
    }


    Num operator++()
    {
        ++num1;
        ++num2;
        return *this;
    }

    Num operator++(int)
    {   
        Num temp = *this;
         num1++;
         num2++;
         return temp;
    }

    Num operator*(const Num &obj)
    {
        return Num(num1 * obj.num1,num2*obj.num2);
    }

    void operator<<(int num)
    {
        cout << "shift value is " << num << endl;
        num1 = num1 << num;
    }
};

int main()
{
    Num obj1;
    Num obj2;
    cout << "+" << endl;
    Num obj3 = obj1 + obj2;
    obj3.display();

    cout << "++obj" << endl;
    Num objn = (++obj1);
    objn.display();

    cout << "obj++" << endl;
    Num objk = obj2++;
    objk.display();
    obj2.display();

    cout << "*" << endl;
    Num obj_mul = obj1 * obj2;
    obj_mul.display();

    cout << "<<" << endl;
    Num obj_shift;
    obj_shift << 2;
    obj_shift.display();

    return 0;
}