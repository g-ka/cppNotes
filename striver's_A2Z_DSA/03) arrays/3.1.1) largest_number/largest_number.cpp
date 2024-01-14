#include <iostream>

int largestNumberOf(int a[], int);

int main(){

  int numbers[] = {3,10,15,2,1,29,21,5};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int largestNumber;

  largestNumber = largestNumberOf(numbers, SIZE);

  std::cout << "The largest number: " << largestNumber;

  return 0;
}

int largestNumberOf(int a[], const int SIZE){

  int largeNum = a[0];
  
  for(int i=1; i<SIZE; i++){
    if(a[i] > largeNum) largeNum = a[i];
  }

  return largeNum;

}