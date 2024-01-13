#include <iostream>
#include <cmath>

bool isPrime(int);

int main(){

  int number;
  int result;

  std::cout << "Enter the number: ";
  std::cin >> number;

  result = isPrime(number);

  std::cout << (result ? "Its a prime number" : "Its not a prime number");

  return 0;
}

bool isPrime(int number){

  for(int i=2; i<=sqrt(number); i++){
    if(number%i == 0){
      return false;
    }
  }

  return true;

}