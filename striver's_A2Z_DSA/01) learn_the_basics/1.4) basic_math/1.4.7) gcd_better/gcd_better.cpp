#include <iostream>
#include <cmath>

int gcdOf(int, int);

int main(){

  int num1, num2;
  int gcd;

  std::cout << "Enter #1: ";
  std::cin >> num1;
  std::cout << "Enter #2: ";
  std::cin >> num2;

  gcd = gcdOf(num1, num2);

  std::cout << "Greatest common divisor: " << gcd;

  return 0;
}

int gcdOf(int num1, int num2){

  for(int i=1; i<=sqrt(std::min(num1, num2)); i++){
    if(std::min(num1, num2)%i == 0){
      if(std::max(num1, num2)%(std::min(num1, num2)/i) == 0){
        return std::min(num1, num2)/i;        
      }
    }
  }

  for(int i=sqrt(std::min(num1, num2)); i>0; i--){
    if(std::min(num1, num2)%i == 0 && std::max(num1, num2)%i == 0){
      return i;
    }
  }

}