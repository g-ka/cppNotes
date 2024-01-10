#include <iostream>

// Ternary operator is a more declarative/short hand way of writing if-else statements

/*
--- if-else ---
if(letter==='a'){
  do_this
}else{
  do_that
}

--- ternary ---
letter===a ? do_this : do_that
*/

int main() {

  int number;

  std::cout << "Enter an integer: ";
  std::cin >> number;

  number%2 ? std::cout << "Its an odd number" : std::cout << "Its an even number";

  std::cout << "\nEnter another number: ";
  std::cin >> number;

  std::cout << (number%2 ? "Its an odd number" : "Its an even number");

  return 0;
}