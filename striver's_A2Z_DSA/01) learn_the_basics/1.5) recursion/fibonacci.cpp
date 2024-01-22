#include <iostream>

void fibonacci(int, int ,int);

int main(){

  int num1 = 1;
  int num2 = 1;

  std::cout << num1 << " " << num2 << " ";

  fibonacci(10,1,1);

  return 0;
}

void fibonacci(int limit, int num1, int num2){
  int temp = num2;
  num2 += num1;
  num1 = temp;
  std::cout << num2 << " ";
  limit--;
  if(limit) fibonacci(limit, num1, num2);
  else return;
}