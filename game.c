#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_int_in_range(const char *prompt, int min, int max) {
    int n;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &n) != 1) {
            int c;
            while ((c = getchar()) != EOF && c != '\n');
            printf("Invalid input — please enter an integer.\n");
            continue;
        }
        if (n < min || n > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        return n;
    }
}

int main(void) {
    int lower = 1, upper = 100;
    char play_again = 'y';
    srand((unsigned) time(NULL));

    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between %d and %d.\n", lower, upper);

    while (play_again == 'y' || play_again == 'Y') {
        int secret = (rand() % (upper - lower + 1)) + lower;
        int attempts = 0;
        int guess;

        printf("\nNew round! Try to guess the number.\n");

        while (1) {
            guess = get_int_in_range("Enter your guess: ", lower, upper);
            attempts++;

            if (guess < secret) {
                printf("Too low. Try again.\n");
            } else if (guess > secret) {
                printf("Too high. Try again.\n");
            } else {
                printf("Correct! You guessed the number in %d attempt%s.\n",
                       attempts, attempts == 1 ? "" : "s");
                break;
            }
        }

        printf("Play again? (y/n): ");
        if (scanf(" %c", &play_again) != 1) {
            break;
        }
        int c;
        while ((c = getchar()) != EOF && c != '\n');

        if (play_again == 'y' || play_again == 'Y') {
            printf("Would you like to change the range? (y/n): ");
            char change_range = 'n';
            if (scanf(" %c", &change_range) == 1) {
                while ((c = getchar()) != EOF && c != '\n');
                if (change_range == 'y' || change_range == 'Y') {
                    int new_lower = get_int_in_range("Enter lower bound (>=0): ", 0, 1000000);
                    int new_upper = get_int_in_range("Enter upper bound (> lower): ", new_lower + 1, 1000000);
                    lower = new_lower;
                    upper = new_upper;
                    printf("Range updated to %d - %d.\n", lower, upper);
                }
            }
        }
    }

    printf("Thanks for playing — goodbye!\n");
    return 0;
}

