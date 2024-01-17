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

  int zeroIndex = -1;
  for(int i=0; i<SIZE; i++){
    if(a[i] == 0 && zeroIndex < 0) zeroIndex = i;
    if(a[i] != 0 && zeroIndex >= 0){
      a[zeroIndex] = a[i];
      a[i] = 0;
      zeroIndex++;
    }
  }

}