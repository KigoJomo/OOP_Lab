#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
    string name;
    int age;
    string breed;

public:
    // Constructor
    Dog(string n, int a, string b) : name(n), age(a), breed(b) {}

    // Method to display dog's details
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Breed: " << breed << endl;
    }

    // Unique function: Bark
    void bark() const {
        cout << name << " says: Woof! Woof!" << endl;
    }

    // Unique function: Fetch
    void fetch() const {
        cout << name << " is fetching the ball!" << endl;
    }
};

int main() {
    // Creating four instances of the Dog class
    Dog dog1("Buddy", 3, "Golden Retriever");
    Dog dog2("Max", 5, "German Shepherd");
    Dog dog3("Bella", 2, "Labrador Retriever");
    Dog dog4("Lucy", 4, "Bulldog");

    // Displaying the details of each dog
    dog1.display();
    dog2.display();
    dog3.display();
    dog4.display();

    // Demonstrating the unique functions
    dog1.bark();
    dog2.bark();
    dog3.fetch();
    dog4.fetch();

    return 0;
}
