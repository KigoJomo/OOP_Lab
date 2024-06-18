#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int random_number_generator()
{
    return rand() % 11 + 10;
}

void guess_the_number(int random_number)
{
    int users_guess;

    while (true)
    {
        cout << "\nGuess the number: ";
        cin >> users_guess;
        if (users_guess == random_number)
        {
            cout << "\nBravo!!! You got it right.";
            cout << "\nThe number is indeed " << random_number << "\n";
            break;
        }
        else
        {
            cout << "\nOoopss! It's not " << users_guess << " ...\nHave another go.\n";
        }
    }
}

int main()
{
    srand(time(0));
    cout << "\nHellooo !!\n";
    cout << "\nGenerating a random number now\n";
    int random_number = random_number_generator();
    Sleep(250);
    cout << "\n.";
    Sleep(250);
    cout << "\n.";
    Sleep(250);
    cout << "\n.";
    Sleep(250);

    cout << "\n\nRandom number generated: **\n";
    // cout << random_number;

    guess_the_number(random_number);

    return 0;
}
