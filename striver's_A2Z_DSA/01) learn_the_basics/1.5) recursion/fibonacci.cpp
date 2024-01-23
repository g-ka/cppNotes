#include <iostream>

void fibonacci(int, int ,int);

int main(){

  int num1 = 1;
  int num2 = 1;
  int limit;

  std::cout << "Enter the numbers(>2): ";
  std::cin >> limit;

  if(limit > 2){
    std::cout << num1 << " " << num2 << " ";
    fibonacci(limit-2,1,1);
  }else std::cout << "Enter number greater than 2";
  
  return 0;
}

void fibonacci(int limit, int num1, int num2){
  int temp = num2;
  num2 += num1;
  num1 = temp;
  limit--;  
  std::cout << num2 << " ";    
  if(limit) fibonacci(limit, num1, num2);
  else return;    
}