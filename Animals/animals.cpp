#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
    string name;
    int age;
    string breed;

public:
    Dog(string n, int a, string b) : name(n), age(a), breed(b) {}

    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Breed: " << breed << endl;
    }

    void bark() const {
        cout << name << " says: Woof! Woof!" << endl;
    }

    void fetch() const {
        cout << name << " is fetching the ball!" << endl;
    }
};

int main() {
    Dog dog1("Buddy", 3, "Golden Retriever");
    Dog dog2("Max", 5, "German Shepherd");
    Dog dog3("Bella", 2, "Labrador Retriever");
    Dog dog4("Lucy", 4, "Bulldog");

    dog1.display();
    dog2.display();
    dog3.display();
    dog4.display();

    dog1.bark();
    dog2.bark();
    dog3.fetch();
    dog4.fetch();

    return 0;
}
