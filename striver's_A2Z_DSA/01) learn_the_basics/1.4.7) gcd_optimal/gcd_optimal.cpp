#include <iostream>

// Euclidian gcd theorem:
/*
-- gcd(a,b) = gcd(a-b, b) where a > b
-- gcd(a,b) = gcd(a%b, b) where a > b
*/

int gcdOf(int, int);

int main(){

  int num1, num2;
  int gcd;

  std::cout << "Enter #1: ";
  std::cin >> num1;
  std::cout << "Enter #2: ";
  std::cin >> num2;

  gcd = gcdOf(num1, num2);

  std::cout << "The gcd: " << gcd;

  return 0;
}

int gcdOf(int num1, int num2){

  int largeNum = std::max(num1, num2);
  int smallNum = std::min(num1, num2);

  while(largeNum && smallNum){    
    int tempSmall = smallNum;
    smallNum = largeNum%smallNum;
    largeNum = tempSmall;
  }

  return largeNum;

}