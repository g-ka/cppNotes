#include <iostream>

void sort(int a[], int);

int main(){

  int numbers[] = {9,13,2,5,30,21,3,8,27,1};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void sort(int a[], const int SIZE){

  for(int i=0; i<SIZE-1; i++){
    for(int j=1; j<SIZE-1-i; j++){
      int smallNum = std::min(a[j-1], std::min(a[j], a[j+1]));
      int largeNum = std::max(a[j-1], std::max(a[j], a[j+1]));
      a[j] = a[j-1] + a[j] + a[j+1] - smallNum - largeNum;
      a[j-1] = smallNum;
      a[j+1] = largeNum;
    }
  }
  
}