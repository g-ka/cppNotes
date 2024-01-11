#include <iostream>

/*
--syntax:
int numbers[] = {1,2,3,4}; => all must be of same datatype(int in this case)
*/

int main() {

  std::string names[3]; // declaration

  // assignment 
  names[0] = "kaphil";
  names[1] = "ganesh";
  names[2] = "tamil";

  std::string cars[] = {"Camaro", "Corvette", "AstonMartin"}; // initialization = declaration + assignment  

  std::cout << names << "\n"; // address of the array i.e address of the first element
  std::cout << cars << "\n"; // address of the array i.e address of the first element  

  std::cout << names[0] << "\n"; //kaphil
  std::cout << names[1] << "\n"; //ganesh
  std::cout << names[2] << "\n"; //tamil

  std::cout << cars[0] << "\n"; //Camaro
  std::cout << cars[1] << "\n"; //Corvetter
  std::cout << cars[2]; //AstonMartin

  return 0;
}