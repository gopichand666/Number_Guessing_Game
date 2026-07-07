#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    char choice;

    do {
        int number = rand() % 100 + 1;
        int guess, attempts = 0;

        cout << "\n=== Number Guessing Game ===" << endl;
        cout << "Guess a number between 1 and 100." << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > number)
                cout << "Too High!" << endl;
            else if (guess < number)
                cout << "Too Low!" << endl;
            else
                cout << "Congratulations! You guessed the number in "
                     << attempts << " attempts." << endl;

        } while (guess != number);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
