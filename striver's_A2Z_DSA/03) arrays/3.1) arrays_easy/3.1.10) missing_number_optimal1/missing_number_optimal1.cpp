#include <iostream>

int missingNumberIn(int a[], int);

int main(){

  int numbers[] = {1,2,3,4,5,6,10,8,9,11};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int missingNumber;

  missingNumber = missingNumberIn(numbers, SIZE);  

  std::cout << "The missing number: " << missingNumber;

  return 0;
}

int missingNumberIn(int a[], const int SIZE){

  int sum = 0;

  for(int i=0; i<SIZE; i++) sum += a[i];

  return (SIZE+1)*(SIZE+2)/2 - sum;
}