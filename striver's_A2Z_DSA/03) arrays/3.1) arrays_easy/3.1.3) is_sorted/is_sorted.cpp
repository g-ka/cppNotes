#include <iostream>

bool isSorted(int a[], int);

int main(){

  int numbers[] = {1,2,3,3,3,4,4,5};
  const int SIZE = sizeof(numbers)/sizeof(int);
  bool result;

  result = isSorted(numbers, SIZE);

  std::cout << (result ? "The array is sorted" : "The array is not sorted");

  return 0;
}

bool isSorted(int a[], const int SIZE){

  if(a[0] < a[1]){
    for(int i=0; i<SIZE-1; i++){
      if(a[i] > a[i+1]) return false;
    }
  }else{
    for(int i=0; i<SIZE-1; i++){
      if(a[i] < a[i+1]) return false;
    }
  }

 return true;
}