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
  for(int i=0; i<SIZE; i++){
    int count = 0;
    for(int j=0; j<SIZE; j++){
      if(a[i] == a[j]) count++;
      // if(count == 2) break;
    }
    if(count < 2) return a[i];
  }
}