#include <iostream>

void sort(int a[],int);

int main(){

  int numbers[] = {13,46,24,52,20,9};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void sort(int a[], const int SIZE){
  
  for(int i=0; i<SIZE-1; i++){

    int smallNumIndex = i; // int largeNumIndex = i
    int smallNum = a[i]; // int largeNum = a[i]

    for(int j=i+1; j<SIZE; j++){
      if(a[j] < smallNum){ // a[j] > largeNum
        smallNumIndex = j; // largeNumIndex = j
        smallNum = a[j]; // largeNum = a[j]    
      }
    }

    int temp = a[i]; // int temp = a[i]
    a[i] = smallNum; // a[i] = largeNum
    a[smallNumIndex] = temp; // a[largeNumIndex] = temp
  }

}