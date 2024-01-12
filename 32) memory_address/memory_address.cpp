#include <iostream>

// & operator => Gives starting memory address of a variable in hexadecimal form

int main() {

  std::string name = "kaphil";
  int number = 1;
  bool isGood = true;

  std::cout << &name << "\n"; //output: starting memory address of name(dynamic)
  std::cout << &number << "\n"; //output: starting memory address of number(dynamic)
  std::cout << &isGood; //output: starting memory address of isGood(dynamic)

  return 0;
}