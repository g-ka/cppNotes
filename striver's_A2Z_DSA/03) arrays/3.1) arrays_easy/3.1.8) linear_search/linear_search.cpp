#include <iostream>

int indexOf(int a[], int, int);

int main(){

  int numbers[] = {3,2,65,4,78,65,12,21,23,9,6,3};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int index;

  index = indexOf(numbers, SIZE, 12);

  if(index == -1) std::cout << "No such element found";
  else std::cout << "Index: " << index;  

  return 0;
}

int indexOf(int a[], const int SIZE, const int K){
  for(int i=0; i<SIZE; i++){
    if(a[i] == K) return i;
  }
  return -1;
}