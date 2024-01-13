#include <iostream>

void sort(int a[], int);

int main(){

  int numbers[] = {13,5,2,18,7,1};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void sort(int a[], const int SIZE){
  
  for(int i=0; i<SIZE-1; i++){
    for(int j=0; j<SIZE-1-i; j++){
      if(a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  
}