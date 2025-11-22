#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if the input is a valid number
int isValidNumber(int *num) {
    if (scanf("%d", num) != 1) {
        while (getchar() != '\n'); // clear invalid input
        return 0; // invalid
    }
    return 1; // valid
}

// Function to check the difference between guess and target
int difference(int guess, int target) {
    return (guess - target);
}

// Function to compare the numbers and give a hint
void compareNumbers(int guess, int target) {
    if (guess < target)
        printf("Too low! Try again.\n");
    else if (guess > target)
        printf("Too high! Try again.\n");
    else
        printf("Correct! You guessed the number! \n");
}

int main() {
    int target, guess;
    srand(time(0)); // seed random generator
    target = rand() % 100 + 1; // random number between 1 and 100

    printf("Welcome to the Guess Number Game!\n");
    printf("I have chosen a number between 1 and 100.\n");

    while (1) {
        printf("\nEnter your guess: ");

        // Validate input
        if (!isValidNumber(&guess)) {
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        // Compare guess and target
        compareNumbers(guess, target);

        // If guessed correctly, break
        if (guess == target)
            break;

        // Show difference (optional feedback)
        printf("You are off by %d.\n", difference(guess, target));
    }

    printf("Thanks for playing!\n");
    return 0;
}
