#include <iostream>
#include <algorithm>

void leftRotateBy(int a[], int, int);

int main(){

  int array[] = {1,2,3,4,5,6,7};
  const int SIZE = sizeof(array)/sizeof(array[0]);
  const int D = 3;

  leftRotateBy(array, SIZE, D);

  for(int element : array){
    std::cout << element << " ";
  }

  return 0;
}

void leftRotateBy(int a[], const int SIZE, int D){
  D %= SIZE;
  std::reverse(a, a+D);
  std::reverse(a+D, a+SIZE);
  std::reverse(a, a+SIZE);
}