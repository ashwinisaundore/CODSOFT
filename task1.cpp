/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    // Initialize guess
    int guess = 0;
    
    // Loop until the user guesses the correct number
    while (guess != secretNumber) {
        // Ask the user to guess the number
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> guess;
        
        // Check if the guess is too high or too low
        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " correctly!" << std::endl;
        }
    }
    
    return 0;
}



