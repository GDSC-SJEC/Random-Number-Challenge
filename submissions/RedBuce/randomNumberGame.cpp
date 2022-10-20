#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    srand(time(0));
    int number;
    number = rand() % 100 + 1;
    int guess;
    int count = 5;
    do {
        if (count == 0) {
            cout<< "You are out of trials" << endl;
            return 0;
        }
        cout << "Enter your guess("<<count<<" trials left): ";
        cin >> guess;
        if (guess < number)
            cout << "Your guess is lesser than the secret number" << endl;
        else if (guess > number)
            cout << "Your guess is more than the secret number" << endl;
        else
            cout << "Your guess is right!" << endl;
        count--;
    } while (guess != number);
}