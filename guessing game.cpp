#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int numberToGuess;
  int numberOfTries;
  int guess;
  bool win = false;

  srand(time(0));
  numberToGuess = (rand() % 10) + 1; // generate random number between 1 and 10

  cout << "Welcome to the number guessing game!" << endl;
  cout << "I'm thinking of a number between 1 and 10." << endl;
  cout << "You have 3 attempts to guess the number." << endl;

  for (numberOfTries = 0; numberOfTries < 3; numberOfTries++) {
    cout << "Enter your guess: ";
    cin >> guess;

    if (guess < numberToGuess) {
      cout << "Too low! Try again." << endl;
    } else if (guess > numberToGuess) {
      cout << "Too high! Try again." << endl;
    } else {
      win = true;
      break;
    }
  }

  if (win) {
    cout << "Congratulations! You guessed the number in " << numberOfTries + 1 << " attempts." << endl;
  } else {
    cout << "Sorry, you didn't guess the number. The number was " << numberToGuess << "." << endl;
  }

  return 0;
}
