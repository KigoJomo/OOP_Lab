#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
    string breed;
    int age;

public:
    Dog(string b, int a) : breed(b), age(a) {}

    void display() const {
        cout << "\n";
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << endl;
    }

    void bark() const {
        cout << breed << " says: Woof! Woof!" << endl;
    }

    void fetch() const {
        cout << breed << " is fetching the ball!" << endl;
    }
};

int main() {
    Dog dog1("Chihuahua", 3);
    Dog dog2("German Shepherd", 5);
    Dog dog3("Rottweiler", 2);
    Dog dog4("Bulldog", 4);

    dog1.display();
    dog1.bark();

    dog2.display();
    dog2.bark();

    dog3.display();
    dog3.fetch();

    dog4.display();
    dog4.fetch();


    return 0;
}
