#include <iostream>

void leftRotateBy(int a[], int, int);

int main(){

  int array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  const int SIZE = sizeof(array)/sizeof(array[0]);
  const int D = 1;

  leftRotateBy(array, SIZE, D);

  for(int element : array){
    std::cout << element << " ";
  }

  return 0;
}

void leftRotateBy(int a[], const int SIZE, int D){

  int store = a[0];
  D = D%SIZE;
  // rotating an array n number of time will result in the original array itself where n = SIZE;

  for(int i=0; i<D; i++){
    for(int i=0; i<SIZE-1; i++){
      a[i] = a[i+1];
    }
    a[SIZE-1] = store;
    store = a[0];
  }

}