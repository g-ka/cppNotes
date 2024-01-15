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
  for(int i=1; i<=SIZE+1; i++){
    int isThere = false;
    for(int j=0; j<SIZE; j++){
      if(a[j] == i) isThere = true;
    }
    if(!isThere) return i;
  }
}