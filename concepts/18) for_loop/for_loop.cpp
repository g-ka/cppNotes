#include <iostream>

/*
syntax: 

for(variable_intitial_value, condition, vaiable_operation){
  do_this
}

It is exclusively used for executing loop for a fixed amount of iterations
*/

int main() {

  for(int i=1; i<=10; i++){
    std::cout << i << "\n";
  }

  std::cout << "HAPPY NEW YEAR";

  return 0;
}