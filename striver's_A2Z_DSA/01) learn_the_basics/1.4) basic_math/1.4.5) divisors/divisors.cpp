#include <iostream>
#include <cmath>

void printDivisorsOf(int);

int main(){

  int number;

  std::cout << "Enter a number: ";
  std::cin >> number;

  printDivisorsOf(number);

  return 0;
}

void printDivisorsOf(int number){

  int end = number;  

  for(int start=1; start <= end; start++){
    double tempNum = number/start;

    if(tempNum*start == number){
      if(start != end){
        std::cout << start << " " << tempNum << " ";
      }else{
        std::cout << start;
      }
    }

    end = number/start - 1;
  }
  
}