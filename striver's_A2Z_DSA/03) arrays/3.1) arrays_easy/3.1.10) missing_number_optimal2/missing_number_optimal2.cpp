#include <iostream>
#include <cmath>

int missingNumberIn(int a[], int);

int main(){

  int numbers[] = {1,2,4,5};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int missingNumber;

  missingNumber = missingNumberIn(numbers, SIZE);  

  std::cout << "The missing number: " << missingNumber;

  return 0;
}

int missingNumberIn(int a[], const int SIZE){

  int sum = 0;

  for(int i=0; i<SIZE; i++){
    if(a[i]%2 != 0) sum += a[i];
    else sum -= a[i];
  }

  return ((pow(-1, SIZE+2))*(SIZE+2)/2 - sum);
}