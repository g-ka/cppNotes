#include <iostream>

void endGroupZeros(int a[], int);

int main(){

  int numbers[] = {20,1,3,0,9,0,0,6,0,0};
  const int SIZE = sizeof(numbers)/sizeof(int);

  endGroupZeros(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void endGroupZeros(int a[], const int SIZE){

  int index = 0;

  for(int i=0; i<SIZE; i++) if(a[i] != 0){
                              a[index] = a[i];
                              index++;
                            }
  

  for(int i=index; i<SIZE; i++) a[i] = 0;

}