#include <iostream>

int gcdOf(int, int);

int main(){

  int num1, num2;
  int result;

  std::cout << "Enter #1: ";
  std::cin >> num1;
  std::cout << "Enter #2: ";
  std::cin >> num2;

  result = gcdOf(num1, num2);

  std::cout << "gcd: " << result;

  return 0;
}

int gcdOf(int num1, int num2){

  int smallNum = num1 - num2 < 0 ? num1 : num2;
  int largeNum = num1 - num2 > 0 ? num1 : num2;

  for(int i=smallNum; i>0; i--){
    if(smallNum%i == 0 && largeNum%i == 0){
      return i;
    }
  }
  
}