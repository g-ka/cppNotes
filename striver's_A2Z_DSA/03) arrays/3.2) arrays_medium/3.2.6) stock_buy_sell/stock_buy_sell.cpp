#include <iostream>

void predict(int a[], int);

int main(){

  int numbers[] = {7,1,5,3,6,4};
  const int SIZE = sizeof(numbers)/sizeof(int);

  predict(numbers, SIZE);

  return 0;
}

void predict(int a[], const int SIZE){

}