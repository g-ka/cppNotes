#include <iostream>

/*
syntax:

do{
  ....
}while(condition);

It will execute the block of code first once, and then checks the 'condition'. 
From then onwards the loop will continue until the condition becomes false/falsy_value
*/

int main() {

  int number;

  do{
    std::cout << "Enter a number(Non-negaitve Integers): ";
    std::cin >> number;
  }while(number < 0);

   std::cout << "You chose " << number << "!";

  return 0;
}