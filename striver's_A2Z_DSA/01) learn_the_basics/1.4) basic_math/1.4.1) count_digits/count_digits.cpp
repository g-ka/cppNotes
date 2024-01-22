#include <iostream>
#include <cmath>

int digitsIn(int);

int main(){

  int number;
  int digits;

  std::cout << "Enter a number(integer): ";
  std::cin >> number;

  digits = digitsIn(number);

  std::cout << "digits: " << digits;

  return 0;
}

int digitsIn(int number){

  int tempNumber = abs(number);
  int digits = 1;

  for(int i=1; floor(tempNumber/pow(10,i)); i++){
    digits = i+1;
  }

  return digits;
}