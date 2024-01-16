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

  int hash[SIZE+2];
  std::fill(hash, hash+SIZE+2, 0);

  for(int i=0; i<SIZE; i++){
    hash[a[i]]++;
  }

  for(int i=1; i<SIZE+1; i++){
    if(hash[i] == 0) return i;
  }
}