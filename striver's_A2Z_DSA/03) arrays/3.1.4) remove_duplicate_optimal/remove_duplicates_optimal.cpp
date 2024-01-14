#include <iostream>

int uniqueNumbersIn(int a[], int);

int main(){

  int numbers[] = {1,1,1,2,2,3,3,3,55,78,89,89,90,91};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int uniqueNumbersCount;

  uniqueNumbersCount = uniqueNumbersIn(numbers, SIZE);

  for(int i=0; i<uniqueNumbersCount; i++){
    std::cout << numbers[i] << " ";
  }

  return 0;
}

// The below function rearranges the original array with all the unique elements sorted initially
// and returns the number of unique charactes
int uniqueNumbersIn(int a[], int SIZE){

  int index = 1;
  int store = a[0];

  for(int i=1; i<SIZE; i++){
    if(a[i] > store){
      a[index] = a[i];
      index++;
      store = a[i];
    }
  }

  return index;

}