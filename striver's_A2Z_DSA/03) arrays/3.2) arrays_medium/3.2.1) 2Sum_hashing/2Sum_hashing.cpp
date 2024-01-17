#include <iostream>

void TwoSumOf(int a[], int, int);

int main(){

  int numbers[] = {2,6,5,8,11};
  const int SIZE = sizeof(numbers)/sizeof(int);  

  TwoSumOf(numbers, SIZE, 14);

  return 0;
}

void TwoSumOf(int a[], const int SIZE, const int K){
  
  int hash[K+1];
  std::fill(hash, hash+K+1, -1);

  for(int i=0; i<SIZE; i++){
    if(hash[K-a[i]] != -1){
      std::cout << "[" << hash[K-a[i]] << " ," << i << "]";
      return;
    }else hash[a[i]] = i;
  }

  std::cout << "No such pair exist";

}