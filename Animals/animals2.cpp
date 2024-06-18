#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal(string name, int age) : name_(name), age_(age) {}

    virtual void speak()
    {
        cout << "Animal sound" << endl;
    }

    string getName() const { return name_; }
    int getAge() const { return age_; }

private:
    string name_;
    int age_;
};

class Dog : public Animal
{
public:
    Dog(string name, int age, string breed) : Animal(name, age), breed_(breed) {}

    void fetch()
    {
        cout << getName() << " the dog fetches the ball!" << endl;
    }

    void wagTail()
    {
        cout << getName() << " wags its tail happily." << endl;
    }

    void speak() override
    {
        cout << getName() << " says: Woof!" << endl;
    }

private:
    string breed_;
};

class Cat : public Animal
{
public:
    Cat(string name, int age) : Animal(name, age) {}

    void purr()
    {
        cout << getName() << " the cat purrs contentedly." << endl;
    }

    void climbTree()    
    {
        cout << getName() << " skillfully climbs a nearby tree." << endl;
    }

    void speak() override
    {
        cout << getName() << " says: Meow!" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird(string name, int age, int wingspan) : Animal(name, age), wingspan_(wingspan) {}

    void fly()
    {
        cout << getName() << " the bird takes flight with a wingspan of " << wingspan_ << " cm." << endl;
    }

    void sing()
    {
        cout << getName() << " sings a beautiful melody." << endl;
    }

    void speak() override
    {
        cout << getName() << " chirps!" << endl;
    }

private:
    int wingspan_;
};

class Fish : public Animal
{
public:
    Fish(string name, int age, string waterType) : Animal(name, age), waterType_(waterType) {}

    void swim()
    {
        cout << getName() << " the fish swims gracefully in " << waterType_ << " water." << endl;
    }

    void bubble()
    {
        cout << getName() << " blows bubbles!" << endl;
    }

    void speak() override
    {
        cout << getName() << " makes a gurgle sound." << endl;
    }

private:
    string waterType_;
};

int main()
{
    Dog dog("Buddy", 3, "Labrador");
    Cat cat("Luna", 2);
    Bird bird("Sparky", 1, 120);
    Fish fish("Finny", 1, "Freshwater");

    cout << dog.getName() << " (age " << dog.getAge() << ") says: ";
    dog.speak();
    dog.fetch();
    dog.wagTail();
    cout << endl;

    cout << cat.getName() << " (age " << cat.getAge() << ") says: ";
    cat.speak();
    cat.purr();
    cat.climbTree();
    cout << endl;

    cout << bird.getName() << " (age " << bird.getAge() << ") says: ";
    bird.speak();
    bird.fly();
    bird.sing();
    cout << endl;

    cout << fish.getName() << " (age " << fish.getAge() << ") says: ";
    fish.speak();
    fish.swim();
    fish.bubble();
    cout << endl;

    return 0;
}
