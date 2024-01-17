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
  int XOR = 0;
  
  for(int i=0; i<SIZE; i++){
    XOR = XOR^a[i];
  }

  return XOR;
}