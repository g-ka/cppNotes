#include <iostream>

int secondLargestOf(int a[], int);

int main(){

  int numbers[] = {3,10,15,2,1,29,21,5};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int secondLargestNumber;

  secondLargestNumber = secondLargestOf(numbers, SIZE);

  std::cout << "The second largest number: " << secondLargestNumber;

  return 0;
}

int secondLargestOf(int a[], const int SIZE){

  int largeNum = a[0];
  int secondLargeNum = INT_MIN;

  for(int i=1; i<SIZE; i++){
    if(a[i] > largeNum){
      secondLargeNum = largeNum;
      largeNum = a[i];    
    }else if(a[i] < largeNum && a[i] > secondLargeNum) secondLargeNum = a[i];
  }

  return secondLargeNum;

}