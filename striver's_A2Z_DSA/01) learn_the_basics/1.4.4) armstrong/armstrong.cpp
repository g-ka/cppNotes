#include <iostream>
#include <cmath>

bool isArmstrong(int);

int main() {

  int number;
  bool result;

  std::cout << "Enter a number: ";
  std::cin >> number;

  result = isArmstrong(number);

  std::cout << (result ? "Its an armstrong number" : "Its not an armstrong number");

  return 0;
}

bool isArmstrong(int number){

  int tempNum1 = number;  
  int tempNum2 = number;
  int digits = 0;
  int armstrongNumber = 0;

  do{
    tempNum1 /= 10;
    digits++;
  }while(tempNum1);
  
  while(tempNum2){
    armstrongNumber += pow(tempNum2%10, digits);
    tempNum2 /= 10;
  }

  return armstrongNumber == number ? true : false;
}