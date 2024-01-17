#include <iostream>

void TwoSumOf(int a[], int, int);

int main(){

  int numbers[] = {9,2,4,5,13,2,1};
  const int SIZE = sizeof(numbers)/sizeof(int);  

  TwoSumOf(numbers, SIZE, 15);

  return 0;
}

void TwoSumOf(int a[], const int SIZE, const int K){
  
  for(int i=0; i<SIZE-1; i++){
    for(int j=i+1; j<SIZE; j++){
      if(a[i] + a[j] == K){
        std::cout << "[" << i << " ," << j << "]";
        return;
      }
    }
  }

  std::cout << "No such pair exist";

}