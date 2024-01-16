#include <iostream>

int NRelIn(int a[], int);

int main(){

  int array[] = {1,2,2,3,4,4,1};
  const int SIZE = sizeof(array)/sizeof(array[0]);
  int NRel;

  NRel = NRelIn(array, SIZE);

  std::cout << "The non-repeating number: " << NRel;
  
  return 0;
}

int NRelIn(int a[], const int SIZE){
  int hash[SIZE+1];
  std::fill(hash, hash+SIZE+1, 0);

  for(int i=0; i<SIZE; i++){
    hash[a[i]]++;
  }

  for(int i=0; i<SIZE+1; i++) if(hash[i] == 1) return i;
}