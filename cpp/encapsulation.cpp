#include <iostream>
#include <string>

class Student {
private: // Data members are private
    std::string name;
    int age;

public: // Methods to access and modify data are public
    // Setter methods
    void setName(const std::string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        } else {
            std::cout << "Invalid age input." << std::endl;
        }
    }

    // Getter methods
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Other methods
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object of the Student class
    Student student1;

    // Accessing and modifying data using methods
    student1.setName("Yashas");
    student1.setAge(25);

    // Displaying information using a method
    student1.displayInfo();

    return 0;
}
