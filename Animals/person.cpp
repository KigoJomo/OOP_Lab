#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int age;
    double height;
    string name;

public:
    // constructor to initailize properties
    Person(int a, double h, string n) : age(a), height(h), name(n){};

    // getter methods to access properties
    int getAge() const { return age; }
    double getHeight() const { return height; }
    string getName() const { return name; }

    // method to display details
    void display()
    {
        cout << "\nName: " << name;
        cout << "\nHeight: " << height;
        cout << "\nAge: " << age;
        cout << "\n";
    }

    // setter methods to change properties
    void setAge(int new_age)
    {
        this->age = new_age;
    }
    void setHeight(double new_height)
    {
        this->height = new_height;
    }
    void setName(string new_name)
    {
        this->name = new_name;
    }
};

int main()
{
    // creating instances(objects) of the class Person

    Person person1(25, 5, "John Doe");
    Person person2(21, 6, "Jane Doe");
    Person person3(22, 5, "Mr Bean");

    // person1.display();
    // person2.display();
    // person3.display();

    // cout << "\nPerson 1 name: " << person1.getName();
    // cout << "\nPerson 1 height: " << person1.getHeight();
    // cout << "\nPerson 1 age: " << person1.getAge();

    cout << "\nUpdate height for " << person1.getName();
    cout << "\nOld height: " << person1.getHeight() << " feet";
    cout << "\nNew Height: ";
    int new_height;
    cin >> new_height;
    person1.setHeight(new_height);
    cout << "\nHeight successfully updated to " << person1.getHeight() << " feet for " << person1.getName();

    return 0;
}
