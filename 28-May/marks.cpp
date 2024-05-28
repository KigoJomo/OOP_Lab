#include <iostream>
#include <string.h>

using namespace std;

class Marks
{
private:
    int m1, m2, sum;
    string grade;

public:
    void getData();
    void displayData();
    void getSum();
    void gradeScore();
};

void Marks::getData()
{
    cout << "\nEnter first subject's mark: ";
    cin >> m1;
    cout << "Enter second subject's mark: ";
    cin >> m2;
}

void Marks::displayData()
{
    cout << "\nFirst subject's marks is: " << m1;
    cout << "\nSecond subject's marks is: " << m2;
}

void Marks::getSum(){
    this->sum = m1 + m2;
    cout << "\nThe sum is: " << this->sum;
}

void Marks::gradeScore(){
    int averageMark = (this->sum) / 2;
    if (averageMark<40){
        this->grade = "Fail";
    }
    else if (averageMark > 40){
        this->grade = "Pass";
    }

    cout << "\nThe average score is: " << averageMark;
    cout << "\nThe average grade is: " << this->grade;
}

int main(){
    Marks x;
    x.getData();
    x.displayData();
    x.getSum();
    x.gradeScore();
}
