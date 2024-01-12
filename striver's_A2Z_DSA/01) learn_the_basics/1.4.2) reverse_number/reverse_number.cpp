#include <iostream>
#include <cmath>

int digitsIn(int);
int reverseNumber(int, int);

int main(){

  int number;
  int digits;
  int reversedNumber;

  std::cout << "Enter a number(integer): ";
  std::cin >> number;

  digits = digitsIn(number);
  reversedNumber = reverseNumber(number, digits);

  std::cout << "Reversed number: " << reversedNumber;

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

// Optimal way to reverse an integer is given in 1.4.3
int reverseNumber(int number, int digits){

  int tempNumber = abs(number);
  int reversedNumber = 0;

  for(int i=0; i<digits; i++){
    reversedNumber += (tempNumber%10)*pow(10, digits-i-1);
    tempNumber = floor(tempNumber/10);
  }
  
  return number > 0 ? reversedNumber : -reversedNumber;

}