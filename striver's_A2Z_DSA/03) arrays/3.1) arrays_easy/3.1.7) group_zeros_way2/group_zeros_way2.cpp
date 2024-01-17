#include <iostream>
#include <algorithm>

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

  int nonZeroCount = 0;

  for(int i=0; i<SIZE; i++) if(a[i] != 0) nonZeroCount++;
  for(int i=0; i!=nonZeroCount; i++) if(a[i] == 0){
                                        std::reverse(a+i, a+i+1);
                                        std::reverse(a+i+1, a+SIZE);
                                        std::reverse(a+i, a+SIZE);
                                        i--;
                                      }
  
}