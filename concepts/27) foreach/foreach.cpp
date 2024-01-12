#include <iostream>

// foreach => eases the traversal process over an iterable data(Ex: array)
/* 
syntax:
for(datatype_of_the_iterables user_defined_element_name : iterable_data) {
  ....
}
*/

int main() {

  std::string cars[] = {"Corvette", "Camaro", "Alto"};
  int numbers[] = {3,4,23,21,5,9};

  for(std::string car : cars) {
    std::cout << car << "\n";
  }

  for(int number : numbers) {
    std::cout << number << "\n";
  }

  return 0;
}