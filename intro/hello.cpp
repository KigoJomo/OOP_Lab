#include <iostream>
using namespace std;

int y, z;
int x = y = z = 50;
int age;
double fees_balance;
char grade;
string name;
bool undergraduate;

const int min_age = 18;

int main()
{
    cout << "Hello!!\n";

    cout << "\n\nWhat's your name?\n";
    cin >> name;

    cout << "\nWhat's your age?";
    cout << "\nMin age: " << min_age << "\n";
    cin >> age;

    cout << "\n\nWhat's your student status?";
    cout << "\n\t1. Undergraduate";
    cout << "\n\t2. Postgraduate";
    cout << "\n\t-----------------------\n\t";
    int graduate_status;
    cin >> graduate_status;

    if(graduate_status == 1){
        undergraduate = true;
    }
    else if(graduate_status == 2){
        undergraduate = false;
    }
    else{
        cout << "Invalid input!\n";
    }

    cout << "\n\n_______________________________";
    cout << "\n\tHello " << name;
    cout << "\n\tYour Age: " << age;
    string student_status = (undergraduate)? "UnderGraduate" : "PostGraduate";
    cout << "\n\tStudent Status: " << student_status;

    return 0;
}
