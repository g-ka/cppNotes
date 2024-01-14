#include <iostream>

void endGroupZeros(int a[], int);

int main(){

  int numbers[] = {0,1,0,3,12};
  const int SIZE = sizeof(numbers)/sizeof(int);

  endGroupZeros(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void endGroupZeros(int a[], const int SIZE){

  int index = SIZE - 1;

  for(int i=0; i<index; i++){
    if(a[i] == 0){
      while(a[index] == 0 && index != i){
        index--;
      }
      a[i] = a[index];
      a[index] = 0;      
      index--;
    }
  }

}