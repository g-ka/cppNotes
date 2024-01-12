#include <iostream>

/*
syntax:

while(condition){
  do_this
}

until the 'condition' becomes/returns false/falsy_values, the while loop keeps on running
*/

int main() {

  std::string name;

  while(name.empty()){
    std::cout << "What is your name: ";
    std::getline(std::cin, name);
  }

  std::cout << "Hello " << name;

  return 0;
}