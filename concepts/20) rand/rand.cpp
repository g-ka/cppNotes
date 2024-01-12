#include <iostream>
// #include <ctime> => might need to include <ctime> library if we use 'time()'

// We should first intialize random number generator and then use 'rand()' to generate random numbers

int main() {

  srand(time(NULL)); //initialize random number generator

  int number = rand(); // generates random number between 0 to 32767
  int diceNumber = rand()%6 + 1; // generates random number between 1 and 6

  std::cout << number << "\n";
  std::cout << diceNumber;

  return 0;
}