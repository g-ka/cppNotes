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
    int tempIndex = i;
    while(a[tempIndex] > a[tempIndex+1] && tempIndex>=0){
      int temp = a[tempIndex+1];
      a[tempIndex+1] = a[tempIndex];
      a[tempIndex] = temp;
      tempIndex--;
    }
  }

}