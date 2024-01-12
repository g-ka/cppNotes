#include <iostream>

int x = 10; //gloabl variable
int y = 20; //global variable

void example();

int main() {

  int x = 30; //local variable to main function

  std::cout << x << " " << y << " " << ::x << "\n"; //30 20 10
  // local variables(x in this case) will override global variables in their local scope
  // However scope resolution operator(::) will help us access the global scoped variable

  example();

  return 0;
}

void example() {
  
  int x = 40;

  std::cout << x << " " << y; //40 20
  // local variables(x in this case) will override global variables in their local scope
}